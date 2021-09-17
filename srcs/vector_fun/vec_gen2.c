/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_gen2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:50:15 by latkins           #+#    #+#             */
/*   Updated: 2021/02/19 21:22:53 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

t_vec	add_product(t_vec a, t_vec b)
{
	t_vec v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vec	multiplay_product(t_vec a, double d)
{
	t_vec v;

	v.x = a.x * d;
	v.y = a.y * d;
	v.z = a.z * d;
	return (v);
}

double	sent_sq(t_vec *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

void	zero_vector(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}
