/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:44:21 by gunkim            #+#    #+#             */
/*   Updated: 2020/11/17 01:07:54 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t ft_lstfree(t_lst *lsthead, t_lst_befreed target)
{
	t_lst		*lst;

	lst = lsthead;
	if (target == all)
	{
		while (lst)
		{
//			ft_bzero(lst->buff, ft_strchr(lst->buff, '\0'));
			free(lst->buff);
			lst = lst->next;
		}
	}
	else if (target == without_tail)
	{
		while (lst->next)
		{
//			ft_bzero(lst->buff, ft_strchr(lst->buff, '\0'));
			free(lst->buff);
			lst = lst->next;
		}
	}
	return (-1);
}

ssize_t	ft_lstinit(t_lst **lsthead, t_lst **lsttail)
{
	if (!*lsttail)
		if (!(*lsthead = (*lsttail = ft_lstnew())))
			return (-1);
	*lsthead = *lsttail;
//	if (0 < ft_strchr((*lsttail)->buff, '\n'))
//		return (0);
	if (!((*lsttail)->next = ft_lstnew()))
		return (ft_lstfree(*lsthead, all));
	*lsttail = (*lsttail)->next;
	return (0);
}

ssize_t	ft_link(char **line, t_lst *lsthead)
{
	ssize_t		linelen;

	linelen = ft_lstlen(lsthead);
	if (!(*line = (char *)malloc(linelen + 1)))
		return (ft_lstfree(lsthead, all));
	ft_lstcpy(*line, lsthead);
	return (1); // 예외처리 필요.
}

ssize_t	ft_split(char **line, t_lst *lsthead, t_lst *lsttail)
{
	char	*tmp;
	ssize_t	idx;

	tmp = lsttail->buff;
	if (0 < (idx = ft_strchr(tmp, '\n')))
	{
		if (!(tmp = (char *)malloc(ft_strchr(tmp, '\0') - idx + 1)))
			return(ft_lstfree(lsthead, all));
		ft_strcpy(tmp, lsttail->buff + idx - 1);
		ft_link(line, lsthead);
		ft_lstfree(lsthead, without_tail);
		free(lsttail->buff);
		lsttail->buff = tmp;
		return (1);
	}
/*	if (*tmp)
	{
		ft_link(line, lsthead);
		ft_lstfree(lsthead, without_tail);
		return (1);
	}*/
	ft_link(line, lsthead);
	ft_lstfree(lsthead, all);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	t_lst			*lsthead;
	static t_lst	*lsttail;
	ssize_t			idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (-1 == (ft_lstinit(&lsthead, &lsttail)))
		return (-1);
	while (0 < (idx = read(fd, lsttail->buff, BUFFER_SIZE)))
	{
		lsttail->buff[idx] = '\0';
		if (0 < ft_strchr(lsttail->buff, '\n'))
			break;
		if (!(lsttail->next = ft_lstnew()))
			return (ft_lstfree(lsthead, all));
		lsttail = lsttail->next;
	}
	if (idx < 0)
		return (ft_lstfree(lsthead, all));
	return (ft_split(line, lsthead, lsttail));
}
