/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fun4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:19:59 by latkins           #+#    #+#             */
/*   Updated: 2021/03/13 12:30:56 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		resol_er9(t_mrt *gen)
{
	int res;

	res = FALSE;
	gen->func = EROR;
	print_error(COL_ERR, 0);
	return (res);
}

int		resol_er10(t_mrt *gen)
{
	int res;

	res = 1;
	if (gen->yy == 0)
	{
		res = FALSE;
		print_error(EMP_ERR, 0);
	}
	else if ((!gen->oka || !gen->okc || !gen->okr) && res == 1)
	{
		res = FALSE;
		print_error(WOR_ERR, 0);
	}
	return (res);
}
