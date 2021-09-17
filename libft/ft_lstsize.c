/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:02:43 by latkins           #+#    #+#             */
/*   Updated: 2020/11/04 20:04:30 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = lst;
	while (cur != 0)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
