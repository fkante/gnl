/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:43:46 by fkante            #+#    #+#             */
/*   Updated: 2019/05/17 17:14:52 by fkante           ###   ########.fr       */
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

static char		*return_the_line(int fd)
{
	char			buf[BUF_SIZE + 1];
	int				cpy_index;
	static int		buff_index;
	static char		*str_until_newline;
	static char		*str_after_newline;
	char			*str_full;
	int				buff_max;
	int				i_scan_str;

	i_scan_str = 0;
	buff_index = buff_index;
	buff_max = read(fd, buf, BUF_SIZE);
	//printf("buff_max:%d\n", buff_max);
	while (find_the_newline(buf[buff_index - 1], '\n') != 0)
	//while (buff_index < BUF_SIZE)
	{
		//if (find_the_newline(buf[buff_index], '\n') == 0)
		//{
		if(!(str_until_newline = (char*)malloc(buff_index + 1 * sizeof(char))))
			return (0);
		cpy_index = 0;
		while (cpy_index < buff_index)
		{
			str_until_newline[cpy_index] = buf[cpy_index];
			cpy_index++;
		}
		cpy_index = 0;
		//}
		buff_index++;
	}
	str_until_newline[buff_index] = '\0';
	//buff_index = 0;
	//printf("str_after_newline:%s\n", str_after_newline);
	//printf("str_until_newline:%s\n", str_until_newline);
	//printf("str_full:%s\n", str_full);
	return (str_full);
	//}
	//	return (NULL);
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
