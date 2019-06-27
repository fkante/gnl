/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:47:17 by fkante            #+#    #+#             */
/*   Updated: 2019/05/23 14:45:35 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		count_lines;
	char	*filename;

	line = NULL;
	if (ac == 1)
		return (1);
	count_lines = 0;
	filename = av[1];
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		count_lines++;
		ft_putstr(line);
		ft_putchar('\n');
		if (count_lines > 50)
			break;
	}
/*	while (get_next_line(fd, &line) > 0)
	{
	}*/
	close(fd);
	return (0);
}
