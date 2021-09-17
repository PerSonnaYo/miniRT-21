/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:37:02 by latkins           #+#    #+#             */
/*   Updated: 2021/02/28 16:21:47 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tabul(char c)
{
	return (c == ' ' || c == '\t');
}

size_t		lw1(char const *s)
{
	int		i;
	size_t	r;

	i = 0;
	r = 0;
	while (s[i] && !tabul(s[i]))
	{
		++i;
		++r;
	}
	return (r);
}

size_t		count_words1(char const *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		while (*str && tabul(*str))
			++str;
		if (*str)
			++i;
		while (*str && !tabul(*str))
			++str;
		i++;
	}
	return (i);
}

char		*cp1(char const *s)
{
	char	*ju;
	size_t	i;

	if (!(ju = (char*)malloc(sizeof(char) * (lw1(s) + 1))))
		return (NULL);
	i = 0;
	while (*s && !tabul(*s))
		ju[i++] = *s++;
	ju[i] = '\0';
	return (ju);
}

char		**ft_split_tab(char const *s)
{
	int		y;
	char	**ju;

	y = 0;
	if (!(s) || !(ju = malloc(sizeof(char*) * (count_words1(s) + 1))))
		return (NULL);
	while (*s)
	{
		while (tabul(*s) && *s)
			++s;
		if (!tabul(*s) && *s)
		{
			if (!(ju[y++] = cp1(s)))
			{
				ft_freetab(ju, count_words1(s));
				return (NULL);
			}
			s = s + lw1(s);
		}
	}
	ju[y] = NULL;
	return (ju);
}
