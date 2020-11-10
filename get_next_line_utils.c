/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:03 by gunkim            #+#    #+#             */
/*   Updated: 2020/11/10 10:50:47 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *buff)
{
	t_list		*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lstnew->buff = buff;
	lstnew->next = NULL;
	return (lstnew);
}

size_t	ft_strlen(char *s)
{
	size_t		len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		s;
	size_t		d;

	s = 0;
	d = ft_strlen(dst);
	if (size <= d)
		return (ft_strlen(src) + size);
	while (src[s] && (d + s + 1 < size))
	{
		dst[d + s] = src[s];
		s++;
	}
	dst[d + s] = '\0';
	return (s + ft_strlen(src + s) + d);
}