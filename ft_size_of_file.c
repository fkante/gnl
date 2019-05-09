/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_of_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:57:02 by fkante            #+#    #+#             */
/*   Updated: 2019/05/08 15:59:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** includes for linux needed for Open, Read and Write 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE_1 1

int		ft_size_of_file(int fd)
{
	int		size_file;
	char	buf[BUF_SIZE_1 + 1];

	size_file = 0;
	while (read(fd, buf, BUF_SIZE_1))
		size_file++;
	return (size_file);
}
