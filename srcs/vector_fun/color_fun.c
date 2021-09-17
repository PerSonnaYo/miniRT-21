/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:05:26 by latkins           #+#    #+#             */
/*   Updated: 2021/02/22 18:08:20 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

t_col	multi_doub(t_col *col, double v)
{
	t_col al;

	al.r = (double)col->r * v;
	al.g = (double)col->g * v;
	al.b = (double)col->b * v;
	return (al);
}

void	init_color(t_col *col)
{
	col->r = 0;
	col->g = 0;
	col->b = 0;
}

t_col	int_tocol(int r, int g, int b)
{
	t_col col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

t_col	proportion(t_col a, t_col v)
{
	double r;
	double g;
	double b;

	r = (double)a.r * (double)v.r / 255;
	g = (double)a.g * (double)v.g / 255;
	b = (double)a.b * (double)v.b / 255;
	return (int_tocol(r, g, b));
}

t_col	add_colors(t_col a, t_col v)
{
	t_col col;

	col.r = (a.r + v.r < 255) ? a.r + v.r : 255;
	col.g = (a.g + v.g < 255) ? a.g + v.g : 255;
	col.b = (a.b + v.b < 255) ? a.b + v.b : 255;
	return (col);
}
