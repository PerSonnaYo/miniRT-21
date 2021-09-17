/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:35:14 by latkins           #+#    #+#             */
/*   Updated: 2021/03/11 15:03:41 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int		count_words2(char **map, int s, t_mrt *gen)
{
	int			i;
	static int	size[9];

	size[0] = 3;
	size[1] = 3;
	size[2] = 4;
	size[3] = 4;
	size[4] = 4;
	size[5] = 4;
	size[6] = 5;
	size[7] = 6;
	size[8] = 5;
	i = 0;
	while (map[i])
		i++;
	if (size[s] == i)
		return (1);
	else
	{
		gen->func = EROR;
		print_error(WOR_ERR, gen->num_line);
	}
	return (0);
}

int		numbers(char *s)
{
	int i;

	i = 0;
	if (s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '.')
			return (0);
		if (s[i] == '.' && (s[i + 1] == '.' || s[i + 1] == '\0'))
			return (0);
		i++;
	}
	return (1);
}

void	initt(t_mrt *gen)
{
	gen->lgt = NULL;
	gen->cam = NULL;
	gen->elem = NULL;
	gen->func = 0;
	gen->num_line = 0;
	gen->camer1 = 0;
	gen->camer = 0;
	gen->pov = 0;
	gen->rr = 0;
	gen->key = 0;
	gen->yy = 0;
	gen->okr = 0;
	gen->oka = 0;
	gen->okc = 0;
}
