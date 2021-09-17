/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fun3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:51:45 by latkins           #+#    #+#             */
/*   Updated: 2021/03/09 13:15:38 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

t_vec	ft_normal(t_vec nor, t_vec ray)
{
	t_vec	oop;
	double	vpr;
	t_vec	normal;

	normal = nor;
	oop = multiplay_product(ray, -1);
	vpr = dot_product(nor, oop);
	if (vpr != 0)
	{
		normal = multiplay_product(nor, vpr);
		normalization(&normal);
	}
	return (normal);
}

t_matx	camera_rotat(t_vec za, t_vec xa, t_vec ya)
{
	t_matx m;

	m.m[0][0] = xa.x;
	m.m[0][1] = xa.y;
	m.m[0][2] = xa.z;
	m.m[1][0] = ya.x;
	m.m[1][1] = ya.y;
	m.m[1][2] = ya.z;
	m.m[2][0] = za.x;
	m.m[2][1] = za.y;
	m.m[2][2] = za.z;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	return (m);
}
