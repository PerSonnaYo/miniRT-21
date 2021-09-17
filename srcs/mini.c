/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:38:03 by latkins           #+#    #+#             */
/*   Updated: 2021/03/13 12:47:57 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

int				print_error(char *err, int l)
{
	if (l == 0)
	{
		write(2, "Error:\n", 7);
	}
	else
	{
		write(2, "Error:\nLine", 12);
		ft_putnbr_fd(l, 2);
		write(2, "\n", 1);
	}
	ft_putstr_fd(err, 2);
	write(2, "\n", 1);
	return (-1);
}

static int		show_win(t_mrt *gen)
{
	t_mlx mlx;

	if ((mlx.param = mlx_init()) == NULL)
		return (FALSE);
	mlx_get_screen_size(mlx.param, &mlx.wmax, &mlx.hmax);
	gen->coor.w = (gen->coor.w > mlx.wmax) ? mlx.wmax : gen->coor.w;
	gen->coor.h = (gen->coor.h > mlx.hmax) ? mlx.hmax : gen->coor.h;
	mlx.op = mlx_new_window(mlx.param, gen->coor.w, gen->coor.h, "miniRT");
	if (mlx.op == NULL)
		return (FALSE);
	if ((mlx.pic = mlx_new_image(mlx.param, gen->coor.w, gen->coor.h)) == NULL)
		return (FALSE);
	mlx.addr = mlx_get_data_addr(mlx.pic, &mlx.bbp, &mlx.size, &mlx.end);
	if (mlx.addr == NULL)
		return (FALSE);
	gen->mlx = mlx;
	mlx_hook(gen->mlx.op, 2, (1L << 0), keyhook, gen);
	mlx_hook(gen->mlx.op, 17, (1L << 17), close_window, gen);
	gen->camer = 1;
	raytracing(gen);
	mlx_put_image_to_window(gen->mlx.param, gen->mlx.op, gen->mlx.pic, 0, 0);
	mlx_loop(gen->mlx.param);
	(void)mlx;
	return (TRUE);
}

static int		parser(t_mrt *gen, int fd)
{
	char	*line;
	int		res;

	res = 1;
	initt(gen);
	while (res > 0)
	{
		line = NULL;
		res = get_next_line(fd, &line);
		gen->num_line++;
		if (res != -1)
		{
			if (parcing(line, gen) == -1)
				res = -1;
			free(line);
			line = NULL;
		}
	}
	res = gen->func != EROR ? 1 : FALSE;
	res = (res == FALSE) ? res : resol_er10(gen);
	return (res);
}

static int		minirt(int ac, char **ag, t_mrt *gen)
{
	int	fd;
	int	res;

	res = TRUE;
	if ((fd = open(ag[1], O_RDONLY)) > 0 &&
		ft_strnstr(ag[1], ".rt", ft_strlen(ag[1])))
	{
		if (parser(gen, fd) == 1)
		{
			close(fd);
			if (ac == 2)
			{
				res = show_win(gen);
				res == FALSE ? print_error(MIL_ERR, 0) : 0;
			}
			else if (ac == 3 && !ft_strncmp(ag[2], "--save", 7))
				res = ac3(gen);
			else
				res = resol_er7(gen);
		}
	}
	else
		res = resol_er8(gen);
	return (res);
}

int				main(int ac, char **ag)
{
	int		res;
	t_mrt	gen;

	res = 0;
	if (ac == 2 || ac == 3)
		res = minirt(ac, ag, &gen);
	else
		res = print_error(ARG_ERR, 0);
	return (res);
}
