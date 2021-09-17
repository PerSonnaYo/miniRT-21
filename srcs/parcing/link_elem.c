/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:00:50 by latkins           #+#    #+#             */
/*   Updated: 2021/03/06 10:28:40 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void	link_sp(t_elem **elem, t_mrt *gen, t_sp sp)
{
	t_elem *new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		exit(EXIT_FAILURE);
	if (new)
	{
		new->vie = SPHERE;
		new->fige.sp = sp;
		new->next = NULL;
	}
	ft_lstadd_front1(elem, new);
	gen->elem = *elem;
}

void	link_pl(t_elem **elem, t_mrt *gen, t_pl pl)
{
	t_elem *new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		exit(EXIT_FAILURE);
	if (new)
	{
		new->vie = PLANE;
		new->fige.pl = pl;
		new->next = NULL;
	}
	ft_lstadd_front1(elem, new);
	gen->elem = *elem;
}

void	link_sq(t_elem **elem, t_mrt *gen, t_sq sq)
{
	t_elem *new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		exit(EXIT_FAILURE);
	if (new)
	{
		new->vie = SQUARE;
		new->fige.sq = sq;
		new->next = NULL;
	}
	ft_lstadd_front1(elem, new);
	gen->elem = *elem;
}

void	link_cy(t_elem **elem, t_mrt *gen, t_cy cy)
{
	t_elem *new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		exit(EXIT_FAILURE);
	if (new)
	{
		new->vie = CYLINDER;
		new->fige.cy = cy;
		new->next = NULL;
	}
	ft_lstadd_front1(elem, new);
	gen->elem = *elem;
}

void	link_tr(t_elem **elem, t_mrt *gen, t_tr tr)
{
	t_elem *new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		exit(EXIT_FAILURE);
	if (new)
	{
		new->vie = TRIANGLE;
		new->fige.tr = tr;
		new->next = NULL;
	}
	ft_lstadd_front1(elem, new);
	gen->elem = *elem;
}
