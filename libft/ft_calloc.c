/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:38:30 by latkins           #+#    #+#             */
/*   Updated: 2021/03/04 11:11:52 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t size)
{
	char *get;

	if (!(get = malloc(c * size)))
		return (NULL);
	ft_bzero(get, c * size);
	return (get);
}
