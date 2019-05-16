/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:43:46 by fkante            #+#    #+#             */
/*   Updated: 2019/05/16 16:53:37 by fkante           ###   ########.fr       */
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

#define BUF_SIZE 15

static int		find_the_newline(const char s1, const char s2)
{
	if (s1 == s2)
		return (0);
	else
		return ((unsigned char)s1 - (unsigned char)s2);
}

static char		*store_the_rest_of_the_buffer(char *buffer, int buff_index)
{
	static char	*str_after_newline;
	int			cpy_index;

	cpy_index = 0;
	if(!(str_after_newline = (char*)malloc((BUF_SIZE - buff_index) + 1 * sizeof(char))))
		return (0);
	while (buff_index < BUF_SIZE)
	{
		str_after_newline[cpy_index] = *buffer++;
		cpy_index++;
		buff_index++;
	}
	str_after_newline[cpy_index] = '\0';
//	printf("str_after_newline: %s\n", str_after_newline);
	return (str_after_newline);
}


static char		*return_the_line(int fd)
{
	char			buf[BUF_SIZE + 1];
	int				cpy_index;
	static int		buff_index;
	static char		*str_until_newline;
	static char		*str_after_newline;
	char		*str_full;

	buff_index = buff_index;
	if (read(fd, buf, BUF_SIZE))
	{
		while (buff_index < BUF_SIZE)
		{
			if (find_the_newline(buf[buff_index] , '\n') == 0)
			{
				if(!(str_until_newline = (char*)malloc(buff_index + 1 * sizeof(char))))
					return (0);
				cpy_index = 0;
				while (cpy_index < buff_index)
				{
					str_until_newline[cpy_index] = buf[cpy_index];
					cpy_index++;
				}
				cpy_index = 0;
				str_until_newline[buff_index] = '\0';
				str_after_newline = store_the_rest_of_the_buffer(&buf[buff_index], buff_index);
				str_full = ft_strjoin(str_until_newline, str_after_newline);
			}
			buff_index++;
		}
		buff_index = 0;
		return (str_until_newline);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	int		nb_line;
	int		test_index = 0;
	char	buf[BUF_SIZE + 1];

	if(!(line = (char**)malloc(OPEN_MAX * sizeof(char*))))
		return (0);
	while (test_index < 5)
	{
		*line = return_the_line(fd);
		printf("line[%d]:%s\n", test_index, *line++);
		test_index++;
	}
	return (0);
}
