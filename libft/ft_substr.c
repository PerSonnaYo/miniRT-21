/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:24:16 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:25:16 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		y;
	char	*ju;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	y = ft_strlen(s) - start;
	if (!(ju = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (y-- && len--)
		{
			ju[i] = s[start];
			start++;
			i++;
		}
		ju[i] = '\0';
	}
	else
	{
		ju[i] = '\0';
	}
	return (ju);
}
