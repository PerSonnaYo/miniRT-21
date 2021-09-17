/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:19:28 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:19:34 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int ch)
{
	const char *fr;

	fr = src;
	while (*src)
		src++;
	while (src >= fr)
	{
		if (*src == (char)ch)
			return ((char *)src);
		src--;
	}
	return (NULL);
}
