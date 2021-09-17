/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camcam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:54:35 by latkins           #+#    #+#             */
/*   Updated: 2021/03/06 12:00:30 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

static void	ft_lstadd_front2(t_cam **lst, t_cam *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int			camera1(t_mrt *gen, char **map, t_cam *cam)
{
	double	r;
	int		res;

	res = TRUE;
	r = ft_atoi(map[3]);
	cam->fov = r * M_PI * 0.5;
	if (r < 0 || r > 180)
	{
		res = FALSE;
		gen->func = EROR;
		print_error(FOV_ERR, gen->num_line);
	}
	normalization(&cam->dir);
	return (res);
}

void		link_cam(t_cam *cam, t_cam **caz, int nb)
{
	t_cam *new;

	if (!(new = (t_cam*)malloc(sizeof(t_cam))))
		exit(EXIT_FAILURE);
	if (new)
	{
		new->nbr = nb;
		new->poz = cam->poz;
		new->dir = cam->dir;
		new->fov = cam->fov;
		new->next = NULL;
	}
	ft_lstadd_front2(caz, new);
}

void		cust_cum(int key, t_mrt *gen)
{
	static int chan;

	chan = gen->camer;
	if (key == LEFT && chan > 1)
		chan--;
	else if (key == RIGHT && chan < gen->camer1)
		chan++;
	if (chan > 0)
	{
		gen->camer = chan;
		raytracing(gen);
		mlx_put_image_to_window(gen->mlx.param, gen->mlx.op,
			gen->mlx.pic, 0, 0);
	}
}

t_cam		selcam(t_mrt gen)
{
	while (gen.cam)
	{
		if (gen.cam->nbr == gen.camer)
			return (*gen.cam);
		gen.cam = gen.cam->next;
	}
	return (*gen.cam);
}
