/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fun1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:12:25 by latkins           #+#    #+#             */
/*   Updated: 2021/02/12 19:38:26 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void	resol_er(t_mrt *gen)
{
	gen->func = EROR;
	print_error(TRU_ERR, gen->num_line);
}

void	resol_er1(t_mrt *gen)
{
	gen->func = EROR;
	print_error(UNI_ERR, gen->num_line);
}

int		int_fov(char *s)
{
	int i;

	i = 0;
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i++]))
			return (0);
	}
	return (1);
}

int		ft_lightstr(char *s1, char *s2, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (ft_strlen(s1) > 2)
		return (0);
	return (1);
}

int		ac3(t_mrt *gen)
{
	int res;

	if ((res = save_img(gen)) == TRUE)
		write(1, BMP_SUC, ft_strlen(BMP_SUC));
	else
		print_error(IMG_ERR, 0);
	return (res);
}
