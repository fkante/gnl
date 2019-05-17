/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:04:57 by fkante            #+#    #+#             */
/*   Updated: 2019/05/17 17:30:10 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define BUF_SIZE 100

int		strrest_with_newline(char **line, char **str_rest)
{
	char	*newline_position;
	char	*str_after_newline;

	if (*str_rest == NULL)
		return (0);
	newline_position = ft_strchr(*str_rest, '\n');
	if (newline_position == NULL)
	{
		*line = ft_strdup(*str_rest);
		ft_strdel(str_rest);
		return (0);
	}
	str_after_newline = ft_strdup(newline_position + 1);
	*newline_position = '\0';
	*line = ft_strdup(*str_rest);
	ft_strdel(str_rest);
	*str_rest = str_after_newline;
	return (1);
}

ssize_t		read_buffer(const int fd, char **line, char **str_rest)
{
	char		buff[BUF_SIZE + 1];
	char		*newline_position;
	ssize_t		read_return;
	char		*leaks;

	while ((read_return = read(fd, buff, BUF_SIZE)) > 0)
	{
		buff[read_return] = '\0';
		newline_position = ft_strchr(buff, '\n');
		leaks = *line;
		if (newline_position == NULL)
		{
			*line = ft_strjoin(*line, buff);
			ft_strdel(&leaks);
			continue ;
		}
		*str_rest = ft_strdup(newline_position + 1);
		*newline_position = '\0';
		*line = ft_strjoin(*line, buff);
		ft_strdel(&leaks);
		return (1);
	}
	return (read_return);
}

int		gnl(const int fd, char **line)
{
	static char	*str_rest;

	if (fd < 0 || line == NULL)
		return (-1);
	if (strrest_with_newline(line, &str_rest) == 1)
		return (1);
	return ((int)read_buffer(fd, line, &str_rest));
}
