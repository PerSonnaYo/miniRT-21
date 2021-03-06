/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:25:48 by latkins           #+#    #+#             */
/*   Updated: 2020/11/03 18:25:53 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int n)
{
	if (n >= 'A' && n <= 'Z')
	{
		n = n + 32;
		return (n);
	}
	return (n);
}
