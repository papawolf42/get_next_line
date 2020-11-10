/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:44:21 by gunkim            #+#    #+#             */
/*   Updated: 2020/11/10 10:50:34 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_has_newline(char *buff)
{
	size_t			idx_nl;
	
	idx_nl = 0;
	if (buff == NULL)
		return (0);
	while (buff[idx_nl])
	{
		if (buff[idx_nl++] == '\n')
			return (idx_nl);
	}
	return (0);
}

int		ft_split(t_list *lstback, char **backup, size_t idx_nl)
{
//	char	*buff;
	size_t	len;

//	buff = lstback->buff;
//	buff[idx_nl - 1] = '\0';
	len = ft_strlen(lstback->buff) - idx_nl; // 4 - 3 = 1
	if (!(*backup = (char *)malloc(len + 1)))
		return (1);
	(*backup)[len] = '\0';
	ft_strlcat(*backup , lstback->buff + idx_nl, len + 1);
	lstback->buff[idx_nl - 1] = '\0';
	return (0);
}

size_t	ft_lstlen(t_list *lst)
{
	size_t	len_tatal;

	len_tatal = 0;
	if (lst->buff == NULL) // 가장 처음 호출 돼었을 때, node[0]의 backup이 NULL임.
		lst = lst->next;
	while (lst)
	{
		len_tatal += ft_strlen(lst->buff);
		lst = lst->next;
	}
	return (len_tatal);
}

int		ft_process(char **line, t_list *lst_first, size_t idx_nl, ssize_t rbyte)
{
	t_list	*lst;
	size_t	len_total;

	if (!idx_nl && !rbyte)
		return (0);
	if (!lst_first->buff)
		lst_first = lst_first->next;
	lst = lst_first;
	len_total = ft_lstlen(lst);
	if (!(*line = (char *)malloc(len_total + 1)))
		return (-1);
	while (lst)
	{
		ft_strlcat(*line, lst->buff, len_total + 1);
		lst = lst->next;
	}
	lst = lst_first;
	while (lst)
	{
		free(lst->buff);
		lst = lst->next;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup;
	char			*buff;
	ssize_t			rbyte;
	size_t			idx_nl;
	t_list			*lstback;
	t_list			*lstfront;
	
	if (!(lstback = (lstfront = ft_lstnew(backup))))
		return (-1);
	while (!(idx_nl = ft_has_newline(lstback->buff)) &&
		(buff = (char *)malloc(BUFFER_SIZE + 1)) && 
		(0 < (rbyte = read(fd, buff, BUFFER_SIZE))))
		{
			buff[rbyte] = 0;
			if(!((lstback)->next = ft_lstnew(buff)))
				return (-1);
			lstback = (lstback)->next;
		}	
	if (idx_nl > 0)
		if (ft_split(lstback, &backup, idx_nl))
			return (-1);
	return (ft_process(line, lstfront, idx_nl, rbyte));
}