/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:16:01 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:17:03 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tro;
	void	*ju;
	size_t	y;

	if (!s || !f)
		return (NULL);
	y = ft_strlen(s);
	if (!(ju = (char*)malloc(sizeof(char) * (y + 1))))
		return (NULL);
	ft_bzero(ju, sizeof(char) * y + 1);
	tro = (char*)ju;
	i = 0;
	while (s[i])
	{
		tro[i] = f(i, s[i]);
		++i;
	}
	tro[i] = '\0';
	return (tro);
}
