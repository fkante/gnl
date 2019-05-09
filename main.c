/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:47:17 by fkante            #+#    #+#             */
/*   Updated: 2019/05/09 10:56:52 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd;
	char **line;

	line = 0;
	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDWR);
	get_next_line(fd, line);
	printf("str_new: %s\n", ft_memjoin_str(av[1], av[2]));
	return (0);
}
