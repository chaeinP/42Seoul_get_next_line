/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:58:53 by chaepark          #+#    #+#             */
/*   Updated: 2021/12/01 00:15:23 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1. (fd < 0 || BUFFER_SIZE <= 0) 에러 체크
// 2. 줄바꿈 나올때까지 read로 긁어오기(긁어올때마다 메모리 새로 할당해야겠지?)
// 3. 줄바꿈이 나오면 줄바꿈 전후를 분리해서 따로 저장
// 4. 줄바꿈 전 부분은 리턴하고 후부분은 static 변수에 저장해서 보존

char	*get_read_all_line(int fd, char *prev_line)
{
	char	*buff;
	ssize_t	check;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + (long long)1));
	if (!buff)
		return (0);
	buff[0] = '\0';
	check = 1;
	while (!ft_strchr(buff, '\n') && check)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check <= 0)
		{
			free(buff);
			if (check == 0)
				return (prev_line);
			return (0);
		}
		buff[check] = '\0';
		prev_line = ft_strjoin(prev_line, buff);
		if (!prev_line)
			return (0);
	}
	free(buff);
	return (prev_line);
}

char	*cp_till_cur_line(char *prev_line)
{
	int		i;
	char	*line;

	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
	{
		line[i] = prev_line[i];
		i++;
	}
	if (prev_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_rest_line(char *prev_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	if (!prev_line[i] || (prev_line[i] == '\n' && !prev_line[i + 1]))
	{
		free(prev_line);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(prev_line) - i + 1));
	if (!str)
		return (0);
	i++;
	while (prev_line[i])
		str[j++] = prev_line[i++];
	str[j] = '\0';
	free(prev_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*prev_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	prev_line = get_read_all_line(fd, prev_line);
	if (!prev_line)
		return (0);
	line = cp_till_cur_line(prev_line);
	prev_line = save_rest_line(prev_line);
	return (line);
}
