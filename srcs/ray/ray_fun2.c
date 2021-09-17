/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fun2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:30:20 by latkins           #+#    #+#             */
/*   Updated: 2021/03/09 13:19:37 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void	normalfor_tria(t_vec *e, t_inter *intt, t_tr tr, t_vec *ray)
{
	intt->normal = cross_product(&e[0], &e[1]);
	normalization(&intt->normal);
	intt->point = add_product(intt->poz, multiplay_product(*ray, intt->t));
	intt->col = tr.col;
}

int		save_img(t_mrt *gen)
{
	t_mlx mlx;

	if ((mlx.param = mlx_init()) == NULL)
		return (FALSE);
	mlx_get_screen_size(mlx.param, &mlx.wmax, &mlx.hmax);
	gen->coor.w = (gen->coor.w > mlx.wmax) ? mlx.wmax : gen->coor.w;
	gen->coor.h = (gen->coor.h > mlx.hmax) ? mlx.hmax : gen->coor.h;
	mlx.op = mlx_new_window(mlx.param, gen->coor.w, gen->coor.h, "miniRT");
	if (mlx.op == NULL)
		return (FALSE);
	if ((mlx.pic = mlx_new_image(mlx.param, gen->coor.w, gen->coor.h)) == NULL)
		return (FALSE);
	mlx.addr = mlx_get_data_addr(mlx.pic, &mlx.bbp, &mlx.size, &mlx.end);
	if (mlx.addr == NULL)
		return (FALSE);
	gen->mlx = mlx;
	gen->camer = 1;
	raytracing(gen);
	save_screen(gen->pic, gen->coor);
	mlx_destroy_image(gen->mlx.param, gen->mlx.pic);
	return (TRUE);
}

t_matx	lookat(t_vec at)
{
	t_vec	up;
	t_vec	xa;
	t_vec	ya;
	t_vec	za;
	t_matx	m;

	up = new_vector(0, 1, 0);
	xa = new_vector(1, 0, 0);
	at = multiplay_product(at, -1);
	normalization(&at);
	if (!(at.y == 1 || at.y == -1))
		xa = cross_product(&up, &at);
	za = at;
	normalization(&xa);
	ya = cross_product(&za, &xa);
	normalization(&ya);
	m = camera_rotat(za, xa, ya);
	return (m);
}

t_img	**new_addr(t_win win)
{
	t_img	**pic;
	int		i;

	i = 0;
	if (!(pic = malloc(sizeof(t_img *) * win.h)))
		exit(EXIT_FAILURE);
	while (i < win.h)
	{
		if (!(pic[i] = malloc(sizeof(t_img) * win.w)))
			exit(EXIT_FAILURE);
		i++;
	}
	return (pic);
}

t_img	ad_int(int col)
{
	t_img	ju;
	t_col	caz;

	caz = pad_col(col);
	ju.r = caz.r;
	ju.g = caz.g;
	ju.b = caz.b;
	return (ju);
}
