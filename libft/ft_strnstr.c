/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:18:45 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:18:49 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] && i + j < len)
	{
		if (s1[i + j] == s2[j])
		{
			if (s2[++j] == '\0')
				return ((char*)s1 + i);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
