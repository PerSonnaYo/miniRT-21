/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:10:46 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:10:51 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int ch)
{
	while (*src)
	{
		if (*src == (char)ch)
			return ((char *)src);
		src++;
	}
	if (ch == '\0')
		return ((char*)src);
	return (NULL);
}
