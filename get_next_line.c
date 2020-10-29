/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:44:21 by gunkim            #+#    #+#             */
/*   Updated: 2020/10/28 20:54:42 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE];
	ssize_t		rbyte;

	rbyte = read(fd, buff, BUFFER_SIZE);
	printf("rbyte : %d\n", rbyte);


}
