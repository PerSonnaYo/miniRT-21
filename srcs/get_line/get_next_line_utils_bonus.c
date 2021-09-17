/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:42:13 by latkins           #+#    #+#             */
/*   Updated: 2021/02/28 15:57:38 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char *ju;

	if (!s1 || !s2)
		return (NULL);
	if (!(ju = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(ju, (char*)s1);
	free((void *)s1);
	ft_strcat(ju, (char*)s2);
	return (ju);
}
