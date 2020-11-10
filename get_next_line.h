/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:17:09 by gunkim            #+#    #+#             */
/*   Updated: 2020/11/10 10:51:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct		s_list
{
	char			*buff;
	struct s_list	*next;
}					t_list;

// gnl_util
t_list				*ft_lstnew(char *buff);
size_t				ft_strlen(char *s);
size_t				ft_strlcat(char *dst, char *src, size_t size);

// gnl
size_t				ft_has_newline(char *buff);
int					ft_split(t_list *lstback, char **backup, size_t idx_nl);
size_t				ft_lstlen(t_list *lst);
int					ft_process(char **line, t_list *lst_first, size_t idx_nl, ssize_t rbyte);
int					get_next_line(int fd, char **line);

// main
//int					main_gnl(void);

#endif
