/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fun3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:42:40 by latkins           #+#    #+#             */
/*   Updated: 2021/03/06 10:28:30 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		resol_er6(t_mrt *gen)
{
	int res;

	res = FALSE;
	gen->func = EROR;
	print_error(TRU_ERR, gen->num_line);
	return (res);
}

int		resol_er7(t_mrt *gen)
{
	int res;

	res = FALSE;
	gen->func = EROR;
	print_error(SAV_ERR, 0);
	return (res);
}

int		resol_er8(t_mrt *gen)
{
	int res;

	res = FALSE;
	gen->func = EROR;
	print_error(FD1_ERR, 0);
	return (res);
}

void	init_inter(t_inter *gg, t_mrt *y)
{
	gg->it = INFINITY;
	y->func = RF;
}

void	ft_lstadd_front1(t_elem **lst, t_elem *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
