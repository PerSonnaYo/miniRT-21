/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:07:32 by latkins           #+#    #+#             */
/*   Updated: 2021/03/11 15:04:04 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		resolution(t_mrt *gen, char **map)
{
	int res;

	res = FALSE;
	if (gen->pov == 0)
	{
		if (numbers(map[1]) && numbers(map[2]))
		{
			gen->coor.w = ft_atoi(map[1]);
			gen->coor.h = ft_atoi(map[2]);
			if (gen->coor.w > 0 && gen->coor.h > 0)
			{
				res = TRUE;
				gen->pov = 1;
			}
			else
				resol_er(gen);
		}
		else
			resol_er(gen);
	}
	else
		resol_er1(gen);
	gen->okr = 1;
	return (res);
}

int		ambient_lightning(t_mrt *gen, char **map)
{
	int res;

	res = FALSE;
	if (gen->pov == 1)
	{
		if (numbers(map[1]))
		{
			gen->am.al = ft_atof(map[1]);
			if (gen->am.al >= 0.0 && gen->am.al <= 1.0)
			{
				res = TRUE;
				gen->pov = 2;
			}
			else
				resol_er2(gen);
		}
		else
			resol_er(gen);
		if (res == TRUE)
			res = am_cor(gen, map);
	}
	else
		resol_er1(gen);
	gen->oka = 1;
	return (res);
}

int		camera(t_mrt *gen, char **map)
{
	int			res;
	t_cam		cam;
	static int	numc;

	numc++;
	res = gektor(map[1], &cam.poz, gen);
	if (res != FALSE)
	{
		res = gektor(map[2], &cam.dir, gen);
		if (!good_vec(&cam.dir))
		{
			res = FALSE;
			gen->func = EROR;
			print_error(NVR_ERR, gen->num_line);
		}
	}
	if (res != FALSE)
		res = (int_fov(map[3])) ? camera1(gen, map, &cam) : resol_er3(gen);
	link_cam(&cam, &gen->cam, numc);
	gen->camer1 = numc;
	gen->camer = numc;
	gen->okc = 1;
	return (res);
}

int		lights(t_mrt *gen, char **map)
{
	t_lgt	lig;
	int		res;

	res = gektor(map[1], &lig.poz, gen);
	if (res != FALSE)
	{
		if (numbers(map[2]))
		{
			lig.its = ft_atof(map[2]);
			res = (lig.its >= 0.0 && lig.its <= 1.0) ? TRUE : resol_er4(gen);
		}
		else
		{
			res = FALSE;
			resol_er(gen);
		}
	}
	if (res != FALSE)
	{
		res = corona(map[3], &lig.col, gen);
		link_lights(&lig, &gen->lgt);
	}
	return (res);
}
