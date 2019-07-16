/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:18:56 by fkante            #+#    #+#             */
/*   Updated: 2019/07/16 19:40:41 by fkante           ###   ########.fr       */
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
	
	if (ac == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		printf("-1\n");
	/*while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}*/
	close(fd);
	return (0);
}
