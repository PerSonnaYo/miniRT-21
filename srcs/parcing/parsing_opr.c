/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_opr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:50:42 by latkins           #+#    #+#             */
/*   Updated: 2021/02/18 14:56:29 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		ft_gain1(int i, t_mrt *gen, char **map)
{
	int			y;
	static int	(*operations[4]) (t_mrt*, char**);

	y = 0;
	operations[0] = &resolution;
	operations[1] = &ambient_lightning;
	operations[2] = &camera;
	operations[3] = &lights;
	y = (operations[i])(gen, map);
	return (y);
}

int		ft_gain2(int i, t_elem **elem, t_mrt *gen, char **map)
{
	int			y;
	static int	(*operations[5]) (t_elem **, t_mrt*, char**);

	y = 0;
	operations[0] = &pl_go;
	operations[1] = &sp_go;
	operations[2] = &sq_go;
	operations[3] = &cy_go;
	operations[4] = &tr_go;
	y = (operations[i])(elem, gen, map);
	return (y);
}

int		ft_gain3(int i, t_vec *ray, t_elem *obj, t_inter *intt)
{
	int			y;
	static int	(*operations[5]) (t_vec*, t_elem*, t_inter*);

	y = 0;
	operations[0] = &pl_in;
	operations[1] = &sp_in;
	operations[2] = &sq_in;
	operations[3] = &cy_in;
	operations[4] = &tr_in;
	y = (operations[i])(ray, obj, intt);
	return (y);
}
