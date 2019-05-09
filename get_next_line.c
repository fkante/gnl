/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:43:46 by fkante            #+#    #+#             */
/*   Updated: 2019/05/09 14:02:09 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "libft.h"

/*
 ** includes for linux needed for Open, Read and Write 
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 20

static int		ft_find_the_newline(int fd)
{
	int			index_newline;
	char		buf[BUF_SIZE + 1];
	const char	newline = 10;

	int buff_scanner = 0;
	index_newline = 0;
	while (read(fd, buf, BUF_SIZE))
	{
		while (buff_scanner < BUF_SIZE)
		{
			printf("strcmp: %d\n", ft_strcmp(&buf[buff_scanner] , newline));
			if (ft_strcmp(&buf[buff_scanner] , "\n") == 0)
				printf("buf = %c\n", buf[buff_scanner]);
			buff_scanner++;
		}
		index_newline++;
	}
	printf("index_newline = %d\n", index_newline);
	printf("buff_scanner = %d\n", buff_scanner);
	return (0);
}

static int		ft_find_the_line(char **line_to_find)
{
	static int line_index;

	line_index = 0;
	printf("pointeur sur char line = %p\n", *line_to_find);
	while (ft_strcmp(*line_to_find, "\n"))
	{
		line_index++;
		//		*line_to_find++;
	}
	return (line_index);
}

int		get_next_line(const int fd, char **line)
{
	ft_find_the_newline(fd);
	//	ft_find_the_line(line);
	return (0);
}
