/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:53:21 by latkins           #+#    #+#             */
/*   Updated: 2021/03/12 19:00:52 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void			zero_inter(t_inter *inter, t_vec ori)
{
	inter->t = INFINITY;
	inter->poz = ori;
	inter->desc = 0;
	inter->desc1 = 0;
	inter->i1 = 0;
	inter->point.x = 0;
	inter->point.y = 0;
	inter->point.z = 0;
	inter->normal.x = 0;
	inter->normal.y = 0;
	inter->normal.z = 0;
	inter->col.r = 0;
	inter->col.g = 0;
	inter->col.b = 0;
}

t_vec			points_square(t_sq sq)
{
	t_vec nor;
	t_vec new;

	nor = (t_vec){0, 1, 0};
	if (sq.dir.y == 1 || sq.dir.y == -1)
		nor = (t_vec){0, 0, 1};
	new = cross_product(&sq.dir, &nor);
	normalization(&new);
	return (new);
}

int				sq_pl(t_vec *ray, t_elem *obj, t_inter *intt)
{
	double zn;

	intt->normal = obj->fige.sq.dir;
	zn = dot_product(*ray, intt->normal);
	if (fabs(zn) > EPSILON)
	{
		intt->t = dot_product(sub_product(obj->fige.sq.poz, intt->poz),
			intt->normal) / zn;
		intt->point = add_product(intt->poz, multiplay_product(*ray, intt->t));
		intt->col = obj->fige.sq.col;
		if (intt->t >= 0 && intt->t < INFINITY)
			return (1);
	}
	return (0);
}

static void		swap_num(double *t)
{
	double y;

	y = t[0];
	t[0] = t[1];
	t[1] = y;
}

int				calc_quadratic(double *d, t_inter *intt)
{
	double t[3];

	t[2] = d[1] * d[1] - 4 * (double)d[0] * (double)d[2];
	if (t[2] < 0)
		return (0);
	else if (t[2] == 0)
	{
		t[0] = -0.5 * d[1] / d[0];
		t[1] = t[0];
	}
	else
	{
		if (d[1] > 0)
			d[3] = -(d[1] + sqrt(t[2])) / 2;
		else
			d[3] = -(d[1] - sqrt(t[2])) / 2;
		t[0] = d[3] / d[0];
		t[1] = d[2] / d[3];
	}
	if (t[0] > t[1])
		swap_num(t);
	intt->desc = t[0];
	intt->desc1 = t[1];
	return (1);
}
