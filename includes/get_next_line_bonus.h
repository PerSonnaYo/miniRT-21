/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:42:42 by latkins           #+#    #+#             */
/*   Updated: 2021/02/28 15:58:23 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFFER_SIZE 50

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin1(char const *s1, char const *s2);
int		init(char **rt, int fd);
int		get_next_line(int fd, char **line);
int		gotto(char *bufi);
int		troko(char **line, char **rt, long count, int fd);
char	*ft_substr1(char *s, unsigned long start, size_t len);

#endif
