/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:58:45 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 17:58:51 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*get;
	const unsigned char	*giv;

	get = dest;
	giv = src;
	if (giv >= get)
		ft_memcpy(get, giv, len);
	else
	{
		get = get + len;
		giv = giv + len;
		while (len > 0)
		{
			*--get = *--giv;
			len--;
		}
	}
	return (dest);
}
