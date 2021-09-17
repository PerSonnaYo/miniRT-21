/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_figu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:33:28 by latkins           #+#    #+#             */
/*   Updated: 2021/03/12 18:55:56 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		sp_in(t_vec *ray, t_elem *obj, t_inter *intt)
{
	double	d[4];
	t_vec	oc;
	double	r;

	r = obj->fige.sp.diam / 2;
	oc = sub_product(intt->poz, obj->fige.sp.poz);
	d[0] = dot_product(*ray, *ray);
	d[1] = 2 * dot_product(*ray, oc);
	d[2] = dot_product(oc, oc) - (r * r);
	if (!calc_quadratic(d, intt))
		return (0);
	if (intt->desc <= EPSILON)
	{
		intt->desc = intt->desc1;
		if (intt->desc <= EPSILON)
			return (0);
	}
	intt->t = intt->desc;
	intt->point = add_product(intt->poz, multiplay_product(*ray, intt->t));
	intt->normal = sub_product(intt->point, obj->fige.sp.poz);
	normalization(&intt->normal);
	intt->col = obj->fige.sp.col;
	if (intt->t < INFINITY)
		return (1);
	return (0);
}

int		pl_in(t_vec *ray, t_elem *obj, t_inter *intt)
{
	double	zn[2];
	t_vec	tmp;

	tmp = sub_product(intt->poz, obj->fige.pl.poz);
	if (dot_product(*ray, obj->fige.pl.dir) > 0)
		obj->fige.pl.dir = multiplay_product(obj->fige.pl.dir, -1);
	zn[0] = dot_product(tmp, obj->fige.pl.dir);
	zn[1] = dot_product(*ray, obj->fige.pl.dir);
	if (zn[1] != 0)
	{
		intt->t = -zn[0] / zn[1];
		intt->point = add_product(intt->poz, multiplay_product(*ray, intt->t));
		intt->col = obj->fige.pl.col;
		intt->normal = obj->fige.pl.dir;
		if (intt->t > 0 && intt->t < INFINITY)
			return (1);
	}
	return (0);
}

int		sq_in(t_vec *ray, t_elem *obj, t_inter *intt)
{
	t_vec	nor;
	double	zn[2];
	t_vec	oc;

	nor = points_square(obj->fige.sq);
	intt->center = cross_product(&nor, &obj->fige.sq.dir);
	normalization(&intt->center);
	if (sq_pl(ray, obj, intt) == 1)
	{
		oc = sub_product(intt->point, obj->fige.sq.poz);
		zn[0] = dot_product(oc, nor);
		zn[1] = dot_product(oc, intt->center);
		if (intt->t > 0 && intt->t < INFINITY)
		{
			if ((fabs(zn[0]) <= obj->fige.sq.h / 2) &&
				(fabs(zn[1]) <= obj->fige.sq.h / 2))
				return (1);
		}
	}
	return (0);
}

int		cy_in(t_vec *ray, t_elem *obj, t_inter *intt)
{
	double d[4];

	if (exic_cy(d, obj->fige.cy, ray, intt) == 0)
		return (0);
	if (intt->desc > 0)
		mark_candidates(&intt->desc, ray, obj->fige.cy, intt);
	if (intt->desc1 > 0)
		mark_candidates(&intt->desc1, ray, obj->fige.cy, intt);
	if (intt->desc1 < 0 && intt->desc < 0)
		return (0);
	if (intt->desc1 < intt->desc)
		intt->t = (intt->desc1 > 0) ? intt->desc1 : intt->desc;
	else
		intt->t = (intt->desc > 0) ? intt->desc : intt->desc1;
	intt->point = add_product(intt->poz, multiplay_product(*ray, intt->t));
	normalfor_cy(obj->fige.cy, intt);
	intt->col = obj->fige.cy.col;
	if (intt->t < INFINITY)
		return (1);
	return (0);
}

int		tr_in(t_vec *ray, t_elem *obj, t_inter *intt)
{
	t_vec	e[2];
	t_vec	vec[3];
	double	zn[4];

	e[0] = sub_product(obj->fige.tr.poz2, obj->fige.tr.poz);
	e[1] = sub_product(obj->fige.tr.poz1, obj->fige.tr.poz);
	vec[0] = cross_product(ray, &e[1]);
	zn[0] = dot_product(e[0], vec[0]);
	if (fabs(zn[0]) < EPSILON)
		return (0);
	zn[1] = 1 / zn[0];
	vec[1] = sub_product(intt->poz, obj->fige.tr.poz);
	zn[2] = dot_product(vec[1], vec[0]) * zn[1];
	if (zn[2] < 0 || zn[2] > 1)
		return (0);
	vec[2] = cross_product(&vec[1], &e[0]);
	zn[3] = dot_product(*ray, vec[2]) * zn[1];
	if (zn[3] < 0 || zn[3] + zn[2] > 1)
		return (0);
	intt->t = dot_product(e[1], vec[2]) * zn[1];
	normalfor_tria(e, intt, obj->fige.tr, ray);
	if (intt->t >= 0 && intt->t < INFINITY)
		return (1);
	return (0);
}
