/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:20:06 by latkins           #+#    #+#             */
/*   Updated: 2021/02/17 19:07:38 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

t_vec	new_vector(double x, double y, double z)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

int		good_vec(t_vec *vic)
{
	if (vic->x >= -1.0 && vic->x <= 1.0 && vic->y >= -1.0 && vic->y <= 1.0
		&& vic->z >= -1.0 && vic->z <= 1.0)
		return (1);
	return (0);
}

int		check_vec(char *s)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '.' && s[i] != ','
			&& s[i] != '+' && s[i] != '-')
			return (0);
		if (ft_isdigit(s[i]) && (s[i + 1] == '+' || s[i + 1] == '-'))
			return (0);
		if ((s[i] == '+' || s[i] == '-') &&
			(s[i + 1] == '+' || s[i + 1] == '-'))
			return (0);
		if (s[i] == '.' && (s[i + 1] == '.' || s[i + 1] == '\0'))
			return (0);
		if (s[i] == ',')
			y++;
		i++;
	}
	if (y != 2 || s[i--] == ',')
		return (0);
	return (1);
}

t_vec	vec_init(char **sub)
{
	t_vec v;

	v.x = ft_atof(sub[0]);
	v.y = ft_atof(sub[1]);
	v.z = ft_atof(sub[2]);
	return (v);
}

int		gektor(char *s, t_vec *vec, t_mrt *gen)
{
	char **sub;

	if (check_vec(s))
	{
		sub = ft_split(s, ',');
		if (sub)
		{
			*vec = vec_init(sub);
			free_map(sub);
		}
		else
		{
			gen->func = EROR;
			print_error(MAL_ERR, gen->num_line);
			return (FALSE);
		}
	}
	else
	{
		gen->func = EROR;
		print_error(VEC_ERR, gen->num_line);
		return (FALSE);
	}
	return (TRUE);
}
