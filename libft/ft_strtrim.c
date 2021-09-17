/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:24:44 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:23:10 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		dret(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*ju;
	size_t			i;
	char const		*s2;

	i = 0;
	s2 = s1;
	if (!s1)
		return (NULL);
	while (*s2)
		s2++;
	while (dret(*s1, set))
	{
		s1++;
	}
	while (dret(*s2, set) || *s2 == '\0')
		s2--;
	if (s2 < s1)
		return (ft_calloc(1, sizeof(char)));
	if (!(ju = malloc(sizeof(char) * ((s2 - s1) + 2))))
		return (NULL);
	while (s1 <= s2)
		ju[i++] = *s1++;
	ju[i] = '\0';
	return (ju);
}
