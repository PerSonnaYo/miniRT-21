/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rey.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:59:44 by latkins           #+#    #+#             */
/*   Updated: 2021/03/12 19:00:26 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void				find_inter(t_mrt *gen, t_vec *ray,
						t_inter *inter, t_cam *cam)
{
	t_inter	intt;
	t_elem	*obj;

	(void)cam;
	obj = gen->elem;
	if (gen->elem)
	{
		while (obj != NULL)
		{
			zero_inter(&intt, inter->poz);
			if (ft_gain3(obj->vie, ray, obj, &intt) > 0)
			{
				gen->func = RT;
				if (intt.t <= inter->it)
				{
					inter->it = intt.t;
					inter->point = intt.point;
					inter->normal = ft_normal(intt.normal, *ray);
					inter->col = intt.col;
				}
			}
			obj = obj->next;
		}
	}
}

t_vec				init_ray(int *y, t_win coor, t_cam cam, t_inter *inter)
{
	t_vec	ray;
	double	g[2];
	t_matx	mi;

	mi = lookat(cam.dir);
	g[0] = tan((double)cam.fov / 180);
	g[1] = (double)coor.w / (double)coor.h;
	ray.x = (2 * (y[1] + 0.5) / (double)coor.w - 1) * g[0] * g[1];
	ray.y = (1 - 2 * (y[0] + 0.5) / (double)coor.h) * g[0];
	ray.z = -1;
	normalization(&ray);
	ray = multiply_atvec(ray, mi);
	normalization(&ray);
	inter->poz = cam.poz;
	return (ray);
}

static double		comp_lighting1(t_vec r, t_vec r1, t_inter inter, double its)
{
	double il;

	r1 = r;
	normalization(&r1);
	il = dot_product(inter.normal, r1);
	if (il > 0)
		il = its * il / ((sqrt(sent_sq(&inter.normal)) * sqrt(sent_sq(&r))));
	il = chek_l(il);
	return (il);
}

int					comp_lighting(t_mrt *gen, t_inter inter)
{
	double	il;
	t_vec	lv[3];
	t_col	col;
	t_lgt	*light;

	il = 0;
	light = gen->lgt;
	init_color(&col);
	zero_vector(&lv[2]);
	if (gen->func == RF)
		return (color_toint(col));
	while (light)
	{
		lv[0] = sub_product(light->poz, inter.point);
		if (shadow(gen->elem, lv[0], &inter))
			il = 0.0;
		else
			il = comp_lighting1(lv[0], lv[1], inter, light->its);
		lv[1] = multiplay_productcol(&light->col, il);
		lv[2] = add_colorsvec(proportionvec(inter.col, lv[1]), lv[2]);
		light = light->next;
	}
	col = int_tocol(lv[2].x, lv[2].y, lv[2].z);
	col = add_colors(proportion(inter.col, gen->am.col), col);
	return (color_toint(col));
}

void				raytracing(t_mrt *gen)
{
	t_cam	comi;
	t_vec	ray;
	t_inter	inter;
	int		y[3];

	gen->pic = new_addr(gen->coor);
	comi = selcam(*gen);
	y[0] = 0;
	while (y[0] < gen->coor.h)
	{
		y[1] = 0;
		while (y[1] < gen->coor.w)
		{
			init_inter(&inter, gen);
			ray = init_ray(y, gen->coor, comi, &inter);
			find_inter(gen, &ray, &inter, &comi);
			y[2] = comp_lighting(gen, inter);
			gen->pic[y[0]][y[1]] = ad_int(y[2]);
			my_mlx_pixel_put(&gen->mlx, y[1], y[0], y[2]);
			y[1]++;
		}
		y[0]++;
	}
}
