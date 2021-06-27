/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:19:14 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strchr_gnl(char *str, char c)
{
	ssize_t	idx;

	idx = 0;
	if (c == '\0')
	{
		while (str[idx])
			idx++;
		return (idx);
	}
	else if (c == '\n')
	{
		while (str[idx])
		{
			if (str[idx] == '\n')
				return (idx + 1);
			idx++;
		}
		return (0);
	}
	return (-1);
}

t_lst	*ft_lstnew_gnl(void)
{
	t_lst			*lstnew;

	if (!(lstnew = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(lstnew->buff = (char *)malloc(BUFFER_SIZE + 1)))
	{
		free(lstnew);
		return (NULL);
	}
	lstnew->buff[BUFFER_SIZE] = '\0';
	lstnew->buff[0] = '\0';
	lstnew->next = NULL;
	return (lstnew);
}

ssize_t	ft_lstlen(t_lst *lst)
{
	ssize_t	strlen;

	strlen = 0;
	while (lst)
	{
		strlen += ft_strchr_gnl(lst->buff, '\0');
		lst = lst->next;
	}
	return (strlen);
}

void	ft_lstcpy(char *dst, t_lst *lst)
{
	char *src;

	while (lst)
	{
		src = lst->buff;
		while (*src)
		{
			*dst++ = *src;
			*src++ = '\0';
		}
		lst = lst->next;
	}
	*dst = '\0';
}

void	ft_strcpy(char *dst, char *src)
{
	*src++ = '\0';
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
}
