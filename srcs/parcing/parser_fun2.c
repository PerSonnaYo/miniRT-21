/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fun2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:39:52 by latkins           #+#    #+#             */
/*   Updated: 2021/02/21 19:33:16 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void	resol_er2(t_mrt *gen)
{
	gen->func = EROR;
	print_error(VAL_ERR, gen->num_line);
}

int		am_cor(t_mrt *gen, char **map)
{
	int res;

	res = corona(map[2], &gen->am.col, gen);
	if (res == TRUE)
		gen->am.col = multi_doub(&gen->am.col, gen->am.al);
	else
	{
		res = FALSE;
		gen->func = EROR;
	}
	return (res);
}

int		resol_er3(t_mrt *gen)
{
	int res;

	res = FALSE;
	gen->func = EROR;
	print_error(INT_ERR, gen->num_line);
	return (res);
}

int		resol_er4(t_mrt *gen)
{
	int res;

	res = FALSE;
	gen->func = EROR;
	print_error(VAL_ERR, gen->num_line);
	return (res);
}

int		resol_er5(t_mrt *gen)
{
	int res;

	res = FALSE;
	gen->func = EROR;
	print_error(NVR_ERR, gen->num_line);
	return (res);
}
