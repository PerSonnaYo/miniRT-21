/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:23:47 by latkins           #+#    #+#             */
/*   Updated: 2021/02/24 15:57:11 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

t_col	pad_col(int color)
{
	t_intimg	new;
	t_col		col;

	new.x = color;
	col.r = new.pad[0];
	col.g = new.pad[1];
	col.b = new.pad[2];
	return (col);
}
