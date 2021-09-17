/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:43:23 by latkins           #+#    #+#             */
/*   Updated: 2021/02/28 16:06:09 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

char	*ft_substr1(char *s, unsigned long start, size_t len)
{
	int		y;
	char	*ju;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	y = ft_strlen(s) - start;
	if (!(ju = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (y-- && len--)
		{
			ju[i] = s[start];
			start++;
			i++;
		}
		ju[i] = '\0';
	}
	else
		ju[i] = '\0';
	free(s);
	return (ju);
}

int		init(char **rt, int fd)
{
	if (!rt[fd])
	{
		if (!(rt[fd] = malloc(sizeof(char))))
			return (-1);
		rt[fd][0] = '\0';
	}
	return (1);
}

int		gotto(char *bufi)
{
	int i;

	i = 0;
	if (!bufi)
		return (-2);
	if (bufi[0] == '\n')
		return (-1);
	while (bufi[i])
	{
		if (bufi[i] == '\n')
			return (i);
		i++;
	}
	return (-2);
}

int		troko(char **line, char **rt, long count, int fd)
{
	int i;

	i = 0;
	if (count == -2)
	{
		i = count;
		count = ft_strlen(rt[fd]);
	}
	if (!(*line = ft_substr(rt[fd], 0, count)))
		return (-1);
	if (i != -2)
	{
		if (!(rt[fd] = ft_substr1(rt[fd], count + 1,
			ft_strlen(rt[fd]) - count)))
			return (-1);
	}
	if (i == -2)
	{
		free(rt[fd]);
		rt[fd] = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	long			u;
	long			count;
	static char		*rt[1024];

	if (fd > 1024 || !line || BUFFER_SIZE <= 0 ||
	(u = read(fd, 0, 0) < 0) || init(rt, fd) < 0)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (gotto(rt[fd]) == -2)
	{
		u = read(fd, buf, BUFFER_SIZE);
		buf[u] = '\0';
		if (*buf == '\0')
			break ;
		if (!(rt[fd] = ft_strjoin1(rt[fd], buf)))
			return (-1);
	}
	free(buf);
	buf = NULL;
	count = gotto(rt[fd]);
	count = (count == -1) ? 0 : count;
	return (troko(line, rt, count, fd));
}
