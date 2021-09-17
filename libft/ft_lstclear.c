/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:16 by latkins           #+#    #+#             */
/*   Updated: 2020/11/05 17:47:14 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur;

	if (!lst || !del)
		return ;
	cur = *lst;
	while (*lst)
	{
		del((*lst)->content);
		cur = *lst;
		*lst = cur->next;
		free(cur);
	}
	*lst = NULL;
}
