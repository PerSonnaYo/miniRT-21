/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:40:56 by latkins           #+#    #+#             */
/*   Updated: 2021/03/13 12:45:16 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		sp_go(t_elem **elem, t_mrt *gen, char **map)
{
	t_sp	sp;
	int		res;

	res = gektor(map[1], &sp.poz, gen);
	if (!(numbers(map[2])) || (sp.diam = ft_atof(map[2])) < 0.0)
	{
		res = FALSE;
		gen->func = EROR;
		print_error(TRU_ERR, gen->num_line);
	}
	if (res != FALSE)
	{
		res = corona(map[3], &sp.col, gen);
		link_sp(elem, gen, sp);
	}
	return (res);
}

int		pl_go(t_elem **elem, t_mrt *gen, char **map)
{
	t_pl	pl;
	int		res;

	res = gektor(map[1], &pl.poz, gen);
	if (res != FALSE)
	{
		res = gektor(map[2], &pl.dir, gen);
		if (!good_vec(&pl.dir))
		{
			res = FALSE;
			gen->func = EROR;
			print_error(NVR_ERR, gen->num_line);
		}
	}
	if (res != FALSE)
	{
		res = corona(map[3], &pl.col, gen);
		normalization(&pl.dir);
		link_pl(elem, gen, pl);
	}
	return (res);
}

int		sq_go(t_elem **elem, t_mrt *gen, char **map)
{
	t_sq	sq;
	int		res;

	res = gektor(map[1], &sq.poz, gen);
	if (res != FALSE)
	{
		res = gektor(map[2], &sq.dir, gen);
		if (!good_vec(&sq.dir))
			res = resol_er5(gen);
	}
	if (numbers(map[3]))
		sq.h = ft_atof(map[3]);
	else
	{
		res = FALSE;
		gen->func = EROR;
		print_error(TRU_ERR, gen->num_line);
	}
	if (res != FALSE)
	{
		res = corona(map[4], &sq.col, gen);
		normalization(&sq.dir);
		link_sq(elem, gen, sq);
	}
	return (res);
}

int		cy_go(t_elem **elem, t_mrt *gen, char **map)
{
	t_cy	cy;
	int		res;

	res = gektor(map[1], &cy.poz, gen);
	if (res != FALSE)
	{
		res = gektor(map[2], &cy.dir, gen);
		if (!good_vec(&cy.dir))
			res = resol_er5(gen);
	}
	if (numbers(map[3]) && numbers(map[4]))
	{
		cy.diam = ft_atof(map[3]);
		cy.h = ft_atof(map[4]);
	}
	else
		res = resol_er6(gen);
	if (res != FALSE)
	{
		res = corona(map[5], &cy.col, gen);
		normalization(&cy.dir);
		link_cy(elem, gen, cy);
	}
	return (res);
}

int		tr_go(t_elem **elem, t_mrt *gen, char **map)
{
	t_tr	tr;
	int		res;

	res = gektor(map[1], &tr.poz, gen);
	if (res != FALSE)
	{
		res = gektor(map[2], &tr.poz1, gen);
		if (res != FALSE)
			res = gektor(map[3], &tr.poz2, gen);
	}
	if (res != FALSE)
	{
		res = corona(map[4], &tr.col, gen);
		link_tr(elem, gen, tr);
	}
	return (res);
}
