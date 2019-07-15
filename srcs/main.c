/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:18:56 by fkante            #+#    #+#             */
/*   Updated: 2019/07/15 16:10:39 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int    main(int ac, char **av) 
{
	char *line;
	int  fd;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		//printf("%s\n", line);
	}
	close(fd);
	return (0);
}
