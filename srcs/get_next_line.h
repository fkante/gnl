/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:22:56 by fkante            #+#    #+#             */
/*   Updated: 2019/05/17 18:32:10 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024

# include "libft/libft.h"
/*
 ** here is two great reading to understand:
 ** file descriptors: http://www.bottomupcs.com/file_descriptors.xhtml
 ** heap and stack: http://stackoverflow.com/a/1213360
 */

int		get_next_line(const int fd, char **line);

#endif
