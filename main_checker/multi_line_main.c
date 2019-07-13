/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:47:17 by fkante            #+#    #+#             */
/*   Updated: 2019/07/13 14:45:37 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int    main(int argc, char const *argv[]) 
{
	int fd;
	int fd_2;
	int i;
	char *line;
	int status;

	fd = open(argv[1], O_RDONLY);
	i = 1;
	(void)fd_2;
	get_next_line(fd, &line);
	printf("zero\n|%s|\n", line);
	free(line);

	fd_2 = open(argv[2], O_RDONLY);
	get_next_line(fd_2, &line);
	printf("first\n|%s|\n", line);
	free(line);

	get_next_line(fd, &line);
	printf("2nd\n|%s|\n", line);
	free(line);
	get_next_line(fd_2, &line);
	printf("3rd\n|%s|\n", line);
	free(line);

	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	return (argc);
}
