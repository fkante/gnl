/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:43:46 by fkante            #+#    #+#             */
/*   Updated: 2019/05/17 16:04:41 by fkante           ###   ########.fr       */
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

static int		ft_strlen_token(const char *str, char token)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != token)
		i++;
	return (i);
}
/*
 ** store until newline seems not to be needed.

static char		*store_until_newline(char *string_sizeof_buffer)
{
	static char	*str_until_newline;
	int			cpy_index;
	int			size_til_newline;

	cpy_index = 0;
	size_til_newline = ft_strlen_token(string_sizeof_buffer, '\n') + 1;
	if(!(str_until_newline = (char*)malloc((size_til_newline + 1))))
		return (0);
	while (cpy_index < size_til_newline)
	{
		str_until_newline[cpy_index] = *string_sizeof_buffer++;
		cpy_index++;
	}
//	printf("str_until_newline: %s\n", str_until_newline);
//	str_until_newline[cpy_index] = '\0';
	return (str_until_newline);
}*/
/************************************************************/

static char		*store_after_newline(char *string_sizeof_buffer)
{
	static char	*str_after_newline;
	int			cpy_index;
	int			size_til_newline;

	cpy_index = 0;
	size_til_newline = ft_strlen_token(string_sizeof_buffer, '\n') + 1;
	if(!(str_after_newline = (char*)malloc((BUF_SIZE + 1))))
		return (0);
	while (size_til_newline < BUF_SIZE)
	{
		str_after_newline[cpy_index] = string_sizeof_buffer[size_til_newline];
		cpy_index++;
		size_til_newline++;
	}
	str_after_newline[cpy_index] = '\0';
//	printf("str_after_newline: %s\n", str_after_newline);
	return (str_after_newline);
}

static char		*return_the_line(int fd)
{
	static char		*str_until_newline;
	static char		*str_after_newline;
	char			buf[BUF_SIZE + 1];
	char			*str_full;
	int				buff_max;
	int				i;
	int				size_next_newline;

	buff_max = read(fd, buf, :wBUF_SIZE);
	//str_full = ft_strdup(buf);
	size_next_newline = ft_strlen_token(buf, '\n');
//	printf("size_next_newline:%d\n", size_next_newline);
	i = 0;
	if(!(str_until_newline = (char*)malloc((size_next_newline + 1))))
		return (0);
	while (i < size_next_newline)
	{
		str_until_newline[i] = buf[i];
		i++;
	}

	//str_until_newline = store_until_newline(str_full);
	/*str_after_newline = store_after_newline(buf);
	i = 0;
	while (str_after_newline[i])
		i++;
	printf("i:%d\n", i);
	char *str_test;
	if(!(str_test = (char*)malloc((i + 1))))
		return (0);
	i = 0;
	while (str_after_newline[i])
	{
		str_test[i] = str_after_newline[i];
		i++;
	}*/
	//printf("str_test:%s\n", str_test);
	//str_full = ft_strjoin(str_until_newline, str_after_newline);
	//printf("str_after_newline:%s\n", str_after_newline);
	printf("str_until_newline:%s\n", str_until_newline);
	//str_full = ft_strjoin(str_after_newline, str_until_newline);
	//printf("str_full:%s\n", str_full);
	//printf("size_next_newline:%d\n", size_next_newline);
	return (NULL);
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
	//printf("line[%d]:%s\n", test_index, *line++);
		test_index++;
	}
	return (0);
}
