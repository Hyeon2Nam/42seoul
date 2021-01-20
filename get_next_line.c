/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:46:40 by hyenam            #+#    #+#             */
/*   Updated: 2021/01/20 21:46:17 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int find_newline(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
	{
		if (!s[i])
			return (-1);
		i++;
	}
	return (i);
}

int get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE + 1];
	static char *temp[OPEN_MAX];
	size_t rd_size;
	int break_point;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	while (0 < (rd_size = read(fd, buff, BUFFER_SIZE)))
	{
		buff[rd_size] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buff);
		break_point = find_newline(temp[fd]);
		if (break_point >= 0)
			printf("%s", temp[fd]);
			// return (ft_newline(&temp[fd], break_point));
	}
	// return (ft_restline(&temp[fd], line, rd_size));
	return (-1);
}