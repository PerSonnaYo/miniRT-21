/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:13:35 by latkins           #+#    #+#             */
/*   Updated: 2020/11/04 18:14:52 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ju;

	if (!(ju = malloc(sizeof(t_list))))
		return (NULL);
	ju->content = content;
	ju->next = NULL;
	return (ju);
}
