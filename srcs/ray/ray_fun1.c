/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fun1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:35:02 by latkins           #+#    #+#             */
/*   Updated: 2021/03/12 18:44:01 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void	mark_candidates(double *t, t_vec *ray, t_cy cy, t_inter *intt)
{
	double	q;
	double	q1;
	t_vec	p2;

	p2 = add_product(cy.poz, multiplay_product(cy.dir, cy.h));
	q1 = dot_product(cy.dir, sub_product(add_product(intt->poz,
		multiplay_product(*ray, *t)), p2));
	q = dot_product(cy.dir, sub_product(add_product(intt->poz,
		multiplay_product(*ray, *t)), cy.poz));
	if (q <= 0)
		*t = -1;
	if (q1 >= 0)
		*t = -1;
}

void	normalfor_cy(t_cy cy, t_inter *intt)
{
	t_vec oc;

	oc = sub_product(intt->point, cy.poz);
	intt->normal = sub_product(oc, multiplay_product(cy.dir,
		dot_product(cy.dir, oc)));
	normalization(&intt->normal);
}

int		exic_cy(double *d, t_cy cy, t_vec *ray, t_inter *intt)
{
	t_vec a;
	t_vec b;
	t_vec c;

	c = sub_product(intt->poz, cy.poz);
	a = sub_product(*ray, multiplay_product(cy.dir,
		dot_product(*ray, cy.dir)));
	b = sub_product(c, multiplay_product(cy.dir, dot_product(c, cy.dir)));
	d[0] = dot_product(a, a);
	d[1] = 2 * dot_product(a, b);
	d[2] = dot_product(b, b) - ((cy.diam * cy.diam) / 4);
	if (calc_quadratic(d, intt))
		return (1);
	return (0);
}

int		shadow(t_elem *obj, t_vec lit_ray, t_inter *inter)
{
	t_inter intt;
	t_vec	normal;
	t_vec	new_ray;

	new_ray = lit_ray;
	normalization(&new_ray);
	normal = multiplay_product(inter->normal, MINT);
	intt.poz = add_product(inter->point, normal);
	while (obj)
	{
		if (ft_gain3(obj->vie, &new_ray, obj, &intt))
		{
			if ((intt.t * intt.t) < sent_sq(&lit_ray))
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int col)
{
	int i;

	i = y * mlx->size + x * (mlx->bbp / 8);
	mlx->addr[i] = (unsigned int)col;
	mlx->addr[++i] = ((unsigned int)col >> 8);
	mlx->addr[++i] = ((unsigned int)col >> 16);
	mlx->addr[++i] = 0;
}
