/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:08:12 by latkins           #+#    #+#             */
/*   Updated: 2021/03/11 15:20:39 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

static void	lun_er(t_mrt *gen, char **map)
{
	if (map[0][0] == '#')
		gen->func = READY;
	else
	{
		gen->func = EROR;
		print_error(TYP_ERR, gen->num_line);
	}
}

static void	lun_em(t_mrt *gen, char **map)
{
	if (map[0] == NULL)
		gen->func = READY;
	else
		gen->func = NORM;
	gen->rr = 1;
}

static void	lun_ev(t_mrt *gen, char **map)
{
	int			i;
	int			res;
	static char	*even[4];

	even[0] = M1R;
	even[1] = M1A;
	even[2] = M1C;
	even[3] = M1L;
	i = 0;
	res = -1;
	while (i < 4)
	{
		if (ft_strncmp(map[0], even[i], 2) == 0)
		{
			if (count_words2(map, i, gen) > 0)
				res = ft_gain1(i, gen, map);
			if (res == TRUE)
				gen->func = READY;
			else
				gen->func = EROR;
		}
		i++;
	}
	gen->rr = 2;
	gen->yy = 1;
}

static void	lun_ob(t_mrt *gen, char **map)
{
	int				i;
	int				res;
	static char		*even[5];
	static t_elem	*elem;

	even[0] = M1PL;
	even[1] = M1SP;
	even[2] = M1SQ;
	even[3] = M1CY;
	even[4] = M1TR;
	i = 0;
	res = -1;
	while (i < 5)
	{
		if (ft_lightstr(map[0], even[i], 3))
		{
			if (count_words2(map, i + 4, gen) > 0)
				res = ft_gain2(i, &elem, gen, map);
			gen->func = (res == TRUE) ? READY : EROR;
		}
		i++;
	}
	gen->rr = 3;
	gen->yy = 1;
}

int			parcing(char *line, t_mrt *gen)
{
	static t_func	oper[4] = {lun_em, lun_ev, lun_ob, lun_er};
	char			**map;
	int				res;

	res = 1;
	map = ft_split_tab(line);
	gen->rr = 0;
	if (map)
	{
		gen->func = NORM;
		while (gen->func == NORM)
		{
			oper[gen->rr](gen, map);
			if (gen->func == EROR)
				res = -1;
		}
		free_map(map);
		map = NULL;
	}
	return (res);
}
