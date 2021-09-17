/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:48:25 by latkins           #+#    #+#             */
/*   Updated: 2021/02/28 19:10:06 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	sw(char *str)
{
	int		i;
	double	res;

	i = 0;
	res = 0;
	while (str[i] && ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return (res);
}

double			ft_atof(char *str)
{
	double	res[2];
	int		i;
	int		gg;

	i = 0;
	res[1] = 0.1;
	gg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		gg = (str[i] == '-') ? -1 : 1;
		i++;
	}
	res[0] = sw(str + i);
	while (str[i] != '.' && str[i])
		++i;
	if (str[i] == '.')
	{
		++i;
		while (str[i] && ft_isdigit(str[i]))
		{
			res[0] = res[0] + (str[i++] - '0') * res[1];
			res[1] = res[1] * 0.1;
		}
	}
	return (gg * res[0]);
}
