/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:43:46 by fkante            #+#    #+#             */
/*   Updated: 2019/05/09 10:59:09 by fkante           ###   ########.fr       */
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

#define BUF_SIZE_1 1

static int		ft_find_the_newline(int fd)
{
	int		index_newline;
	char	buf[BUF_SIZE_1 + 1];

	index_newline = 0;
	while (read(fd, buf, BUF_SIZE_1))
	{
		index_newline++;
		if (buf == "\n")
		{
			printf("size of the file = %d\n", index_newline);
			return (0);
		}
	}
	printf("size of the file = %d\n", index_newline);
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
		*line_to_find++;
	}
	return (line_index);
}

int		get_next_line(const int fd, char **line)
{
	ft_find_the_newline(fd);
	ft_find_the_line(line);
	return (0);
}
