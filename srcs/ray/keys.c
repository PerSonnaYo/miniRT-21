/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:38:09 by latkins           #+#    #+#             */
/*   Updated: 2021/02/28 16:43:33 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		close_window(t_mrt *gen)
{
	mlx_clear_window(gen->mlx.param, gen->mlx.op);
	mlx_destroy_image(gen->mlx.param, gen->mlx.pic);
	mlx_destroy_window(gen->mlx.param, gen->mlx.op);
	free(gen->mlx.param);
	free_elem(&gen->elem);
	free_cam(&gen->cam);
	free_light(&gen->lgt);
	free_pic(gen->pic, gen->coor.h);
	exit(EXIT_SUCCESS);
}

int		keyhook(int key, t_mrt *gen)
{
	if (key == LEFT || key == RIGHT)
		cust_cum(key, gen);
	if (key == KEY_SPACE)
	{
		save_screen(gen->pic, gen->coor);
		write(1, BMP_SUC, ft_strlen(BMP_SUC));
	}
	if (key == ESC)
	{
		close_window(gen);
	}
	return (0);
}
