/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:56:49 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 17:56:53 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t				i;
	const unsigned char	*get;
	const unsigned char	*giv;

	get = s1;
	giv = s2;
	i = 0;
	while (i < len)
	{
		if (get[i] != giv[i])
			return (get[i] - giv[i]);
		i++;
	}
	return (0);
}
