/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:46:58 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 17:49:02 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		dln(int n)
{
	size_t len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n && (n /= 10))
	{
		len++;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char	*ju;
	long	g;
	size_t	len;

	len = dln(n);
	if (!(ju = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ju[len] = '\0';
	g = n;
	if (g == 0)
		ju[0] = 48;
	if (g < 0)
	{
		ju[0] = '-';
		g = g * -1;
	}
	while (g)
	{
		ju[--len] = g % 10 + '0';
		g = g / 10;
	}
	return (ju);
}
