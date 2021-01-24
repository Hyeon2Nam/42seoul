/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:45:37 by hyenam            #+#    #+#             */
/*   Updated: 2021/01/24 21:34:59 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(char *s)
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

static int	line_split(char **line, char **str, int break_point)
{
	char *temp;

	(*str)[break_point] = '\0';
	*line = ft_strdup(*str);
	if (ft_strlen(*str + break_point + 1) == 0)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	temp = ft_strdup(*str + break_point + 1);
	free(*str);
	*str = temp;
	return (1);
}

static int	remaining_line(char **line, char **str, int rd_size)
{
	int break_point;

	if (rd_size < 0)
		return (-1);
	else if (*str && (break_point = find_newline(*str)) >= 0)
		return (line_split(line, str, break_point));
	else if (*str)
	{
		*line = *str;
		*str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*temp[OPEN_MAX];
	int			rd_size;
	int			break_point;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd_size] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buff);
		break_point = find_newline(temp[fd]);
		if (break_point >= 0)
			return (line_split(line, &temp[fd], break_point));
	}
	return (remaining_line(line, &temp[fd], rd_size));
}
