/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:43:46 by fkante            #+#    #+#             */
/*   Updated: 2019/05/15 14:29:45 by fkante           ###   ########.fr       */
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


/*
 ** function test to find the newline, to be implemented in strcmp
 */
static int		ft_strcmp_onechar(const char s1, const char s2)
{
	if (s1 == s2)
		return (0);
	else
		return ((unsigned char)s1 - (unsigned char)s2);
}

static char		*ft_store_the_line(int fd)
{
	static char		buf[BUF_SIZE + 1];
	static int	buff_index;
	int			cpy_index;
	char		*one_line;

	buff_index = buff_index;
	if (read(fd, buf, BUF_SIZE))
	{
		while (buff_index < BUF_SIZE)
		{
			//printf("ft_strcmp: %d\n", ft_strcmp(&buf[buff_index], "\n"));
			//printf("one_line: %c\n", one_line[buff_index]);
			if (ft_strcmp_onechar(buf[buff_index] , '\n') == 0)
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
				return (one_line);
			}
			buff_index++;
		}
	}
	return (ft_store_the_line(fd));
}

int		get_next_line(const int fd, char **line)
{
	int		test_index = 0;

	while (test_index < 2)
	{
		printf("line:%s\n", ft_store_the_line(fd));
		test_index++;
	}
	return (0);
}
