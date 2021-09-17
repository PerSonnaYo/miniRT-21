/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:26:46 by latkins           #+#    #+#             */
/*   Updated: 2021/03/13 13:23:18 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

static void	ft_lstadd_front3(t_lgt **lst, t_lgt *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void		link_lights(t_lgt *lig, t_lgt **lif)
{
	t_lgt *new;

	if (!(new = (t_lgt*)malloc(sizeof(t_lgt))))
		exit(EXIT_FAILURE);
	if (new)
	{
		new->poz = lig->poz;
		new->col = lig->col;
		new->its = lig->its * 4000;
		new->next = NULL;
	}
	ft_lstadd_front3(lif, new);
}
