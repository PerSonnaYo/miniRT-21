/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:53:22 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 17:53:29 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char			*get;
	unsigned char			bor;
	const unsigned char		*giv;

	get = dest;
	giv = src;
	bor = c;
	if (!dest && !src)
		return (dest);
	while (len > 0)
	{
		*get = *giv;
		get++;
		giv++;
		if (*(get - 1) == bor)
			return (get);
		len--;
	}
	return (NULL);
}
