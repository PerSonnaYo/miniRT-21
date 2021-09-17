/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_gen1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:58:21 by latkins           #+#    #+#             */
/*   Updated: 2021/02/22 17:31:37 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

t_vec	multiply_atvec(t_vec v, t_matx m)
{
	t_vec o;

	o.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
	o.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
	o.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
	return (o);
}

t_vec	cross_product(t_vec *a, t_vec *b)
{
	t_vec v;

	v.x = a->y * b->z - b->y * a->z;
	v.y = a->z * b->x - b->z * a->x;
	v.z = a->x * b->y - b->x * a->y;
	return (v);
}

void	normalization(t_vec *a)
{
	double v;

	v = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
	a->x /= v;
	a->y /= v;
	a->z /= v;
}

double	dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	sub_product(t_vec a, t_vec b)
{
	t_vec v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}
