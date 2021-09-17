/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:39:23 by latkins           #+#    #+#             */
/*   Updated: 2021/03/09 14:17:24 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	nb;
	int		s;
	int		r;

	nb = 0;
	r = 1;
	s = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while ((ft_isdigit(*str)) && r == 1)
	{
		nb = (nb * 10) + *str++ - '0';
		if (nb < 0)
			r = (s == 1 ? -1 : 0);
	}
	return (r != 1 ? r : (int)(nb * s));
}
