/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:11:41 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:11:46 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*hy;
	size_t	i;

	hy = malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (!hy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		hy[i] = src[i];
		i++;
	}
	hy[i] = '\0';
	return (hy);
}
