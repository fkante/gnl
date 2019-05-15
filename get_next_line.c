/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:43:46 by fkante            #+#    #+#             */
/*   Updated: 2019/05/15 15:37:21 by fkante           ###   ########.fr       */
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

#define BUF_SIZE 100


/*
 ** function test to find the newline, to be implemented in strcmp
 */
static int		strcmp_onechar(const char s1, const char s2)
{
	if (s1 == s2)
		return (0);
	else
		return ((unsigned char)s1 - (unsigned char)s2);
}

static char		*store_the_line(int fd)
{
	char		buf[BUF_SIZE + 1];
	char		*one_line;
	int			cpy_index;
	static int	buff_index;

	buff_index = buff_index;
	//	printf("buff_index: %d\tBUF_SIZE: %d\n", buff_index, BUF_SIZE);
	//	printf("read %zd\n", read(fd, buf, BUF_SIZE));
	if (read(fd, buf, BUF_SIZE))
	{
		while (buff_index < BUF_SIZE)
		{
			//printf("ft_strcmp: %d\n", ft_strcmp(&buf[buff_index], "\n"));
			if (strcmp_onechar(buf[buff_index] , '\n') == 0)
			{
				if(!(one_line = (char*)malloc(buff_index + 1 * sizeof(char))))
					return (0);
				cpy_index = 0;
				while (cpy_index < buff_index)
				{
					one_line[cpy_index] = buf[cpy_index];
					cpy_index++;
				}
				one_line[buff_index] = '\0';
				buff_index++;
				printf("buff_index:%d\n", buff_index);
				return (one_line);
			}
			buff_index++;
		}
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	int		nb_line;
	int		test_index = 0;

	if(!(line = (char**)malloc(1000 * sizeof(char*))))
		return (0);
	while (test_index < 5)
	{
		*line = store_the_line(fd);
		printf("line[%d]:%s\n", test_index, *line++);
		test_index++;
	}
	return (0);
}
