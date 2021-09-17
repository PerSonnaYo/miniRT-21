/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:55:38 by latkins           #+#    #+#             */
/*   Updated: 2020/11/08 20:43:38 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	bor;
	unsigned char	*get;

	get = (unsigned char*)s;
	bor = (unsigned char)c;
	while (len--)
	{
		if (*get == bor)
			return (get);
		get++;
	}
	return (NULL);
}
