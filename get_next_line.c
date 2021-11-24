/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:58:53 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/24 20:01:22 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		i;
	ssize_t		check;
	static char	*read_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_line = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!read_line)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE){
		check = read(fd, read_line + i, 1);
		if (check <= 0)
			return (0);
		if (read_line[i++] == '\n')
			break;
	}
	read_line[i] = '\0';
	return (read_line);
}
