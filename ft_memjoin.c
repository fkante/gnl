/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:00:55 by fkante            #+#    #+#             */
/*   Updated: 2019/05/16 16:18:39 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoin(char const *str_first, char const *str_last, size_t len_all)
{
	size_t	i;
	char	*str_new;
	size_t	len_first;

	if (str_first == NULL || str_last == NULL)
		return (NULL);
	i = 0;
	len_first = ft_strlen(str_first);
	if (!(str_new = (char *)malloc((len_all + 1) * sizeof(char))))
		return (NULL);
	while (i < len_first)
	{
		str_new[i] = str_first[i];
		i++;
	}
	while (i < len_all)
	{
		str_new[i] = str_last[i - len_first];
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
