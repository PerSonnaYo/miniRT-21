/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:56:30 by latkins           #+#    #+#             */
/*   Updated: 2021/02/22 18:07:47 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

double	chek_l(double v)
{
	v = v / 255;
	v = (v > 1) ? 1 : v;
	v = (v > 0) ? v : 0;
	return (v);
}

t_vec	multiplay_productcol(t_col *a, double d)
{
	t_vec v;

	v.x = (double)a->r * d;
	v.y = (double)a->g * d;
	v.z = (double)a->b * d;
	return (v);
}

t_vec	add_colorsvec(t_vec a, t_vec b)
{
	t_vec col;

	col.x = (a.x + b.x < 255) ? a.x + b.x : 255;
	col.y = (a.y + b.y < 255) ? a.y + b.y : 255;
	col.z = (a.z + b.z < 255) ? a.z + b.z : 255;
	return (col);
}

t_vec	proportionvec(t_col a, t_vec h)
{
	double	r;
	double	g;
	double	b;
	t_vec	v;

	r = (double)a.r * h.x / 255;
	g = (double)a.g * h.y / 255;
	b = (double)a.b * h.z / 255;
	v.x = r;
	v.y = g;
	v.z = b;
	return (v);
}

int		color_toint(t_col col)
{
	return (65536 * col.r + 256 * col.g + col.b);
}
