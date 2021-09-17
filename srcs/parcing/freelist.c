/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:33:02 by latkins           #+#    #+#             */
/*   Updated: 2021/03/06 13:42:29 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

void	free_elem(t_elem **elem)
{
	t_elem *buf;

	while (*elem != NULL)
	{
		buf = *elem;
		*elem = (*elem)->next;
		free(buf);
		buf = NULL;
	}
	*elem = NULL;
}

void	free_pic(t_img **pic, int hei)
{
	int i;

	i = 0;
	while (i < hei)
	{
		free(pic[i]);
		i++;
	}
	free(pic);
}

void	free_cam(t_cam **cam)
{
	t_cam *buf;

	while (*cam != NULL)
	{
		buf = *cam;
		free(buf);
		buf = NULL;
		*cam = (*cam)->next;
	}
	*cam = NULL;
}

void	free_light(t_lgt **light)
{
	t_lgt *buf;

	while (*light != NULL)
	{
		buf = *light;
		free(buf);
		buf = NULL;
		*light = (*light)->next;
	}
	*light = NULL;
}
