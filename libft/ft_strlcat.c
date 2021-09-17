/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:13:21 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:13:51 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t l;
	size_t l1;

	l = ft_strlen(dest);
	l1 = ft_strlen(src);
	if (size < l)
		return (size + l1);
	i = 0;
	while (src[i] != '\0' && (l + i + 1) < size)
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = '\0';
	return (l + l1);
}
