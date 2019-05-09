/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:47:17 by fkante            #+#    #+#             */
/*   Updated: 2019/05/09 12:42:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd;
	char **line;

	line = NULL;
	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDWR);
	get_next_line(fd, line);
//	printf("str_new: %s\n", ft_memjoin_str(av[1], av[2]));
	return (0);
}
