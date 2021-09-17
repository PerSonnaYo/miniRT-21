/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:53:05 by latkins           #+#    #+#             */
/*   Updated: 2021/03/13 12:22:11 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int		good_col(t_col *col)
{
	if (col->r >= 0 && col->r <= 255 && col->g >= 0 && col->g <= 255)
	{
		if (col->b >= 0 && col->b <= 255)
			return (1);
	}
	return (0);
}

t_col	col_init(char **sub)
{
	t_col col;

	col.r = ft_atoi(sub[0]);
	col.g = ft_atoi(sub[1]);
	col.b = ft_atoi(sub[2]);
	return (col);
}

int		check_col(char *s)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',' && s[i] != '+')
			return (0);
		if (ft_isdigit(s[i] && s[i + 1] == '+'))
			return (0);
		if (s[i] == ',')
			y++;
		i++;
	}
	if (y != 2)
		return (0);
	return (1);
}

int		corona(char *s, t_col *col, t_mrt *gen)
{
	char **sub;

	if (check_col(s))
	{
		if ((sub = ft_split(s, ',')))
		{
			*col = col_init(sub);
			free_map(sub);
			if (!good_col(col))
				return (resol_er9(gen));
		}
		else
		{
			gen->func = EROR;
			print_error(MAL_ERR, gen->num_line);
			return (FALSE);
		}
	}
	else
		return (resol_er9(gen));
	return (TRUE);
}
