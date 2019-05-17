/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:47:17 by fkante            #+#    #+#             */
/*   Updated: 2019/05/17 17:13:40 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		gnl(const int fd, char **line);

int		main(int ac, char **av)
{
	int fd;
	char *line;

	line = NULL;
	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDWR);
	while (gnl(fd, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
