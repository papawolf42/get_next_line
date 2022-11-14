/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:17:09 by gunkim            #+#    #+#             */
/*   Updated: 2022/11/14 22:15:41 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef enum
{
	all,
	without_tail
}	t_range;

typedef struct		s_lst
{
	char			*buff;
	struct s_lst	*next;
}					t_lst;

/*
** - gnl_util
*/

ssize_t				ft_strchr_gnl(char *str, char c);
t_lst				*ft_lstnew_gnl();
ssize_t				ft_lstlen(t_lst *lst);
void				ft_lstcpy(char *dst, t_lst *lst);
void				ft_strcpy_gnl(char *dst, char *src);

/*
** - gnl
*/

ssize_t				ft_lstfree(t_lst *lsthead, t_lst **lsttail, t_range range);
ssize_t				ft_lstinit(t_lst **lsthead, t_lst **lsttail);
ssize_t				ft_link(char **line, t_lst *lsthead, t_lst **lsttail);
ssize_t				ft_split_gnl(char **line, t_lst *lsthead, t_lst **lsttail);
int					get_next_line(int fd, char **line);

#endif
