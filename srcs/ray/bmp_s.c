/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:45:59 by latkins           #+#    #+#             */
/*   Updated: 2021/02/28 16:31:02 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt1.h"

static void	bmp_image_header(t_bmpi *bmpi, int imsize, t_win win)
{
	int file_size;

	file_size = 4 * imsize;
	bmpi->head_size = 40;
	bmpi->width = win.w;
	bmpi->height = win.h;
	bmpi->plane = 1;
	bmpi->bit_count = 24;
	bmpi->compres = 0;
	bmpi->imsize = file_size;
	bmpi->w_res = 2835;
	bmpi->h_res = 2835;
	bmpi->color = 0;
	bmpi->imp_col = 0;
}

static void	bmp_file_header(t_bmpf *bmpf, int *row, int height)
{
	int	file_size;

	file_size = 54 + (row[2] + row[3]) * height;
	bmpf->bt[0] = 'B';
	bmpf->bt[1] = 'M';
	bmpf->file_size = file_size;
	bmpf->reser = 0;
	bmpf->offset = 54;
}

static void	write_header(const int fd, t_bmpf *bmpf, t_bmpi *bmpi)
{
	write(fd, &bmpf->bt, 2);
	write(fd, &bmpf->file_size, 4);
	write(fd, &bmpf->reser, 4);
	write(fd, &bmpf->offset, 4);
	write(fd, &bmpi->head_size, 4);
	write(fd, &bmpi->width, 4);
	write(fd, &bmpi->height, 4);
	write(fd, &bmpi->plane, 2);
	write(fd, &bmpi->bit_count, 2);
	write(fd, &bmpi->compres, 4);
	write(fd, &bmpi->imsize, 4);
	write(fd, &bmpi->w_res, 4);
	write(fd, &bmpi->h_res, 4);
	write(fd, &bmpi->color, 4);
	write(fd, &bmpi->imp_col, 4);
}

static void	save_screen1(int *fd, t_img **pic, int hei)
{
	unsigned char	ju[3];

	ju[0] = 0;
	ju[1] = 0;
	ju[2] = 0;
	while (hei--)
	{
		write(fd[0], pic[hei], fd[2]);
		write(fd[0], ju, fd[3]);
	}
}

void		save_screen(t_img **pic, t_win win)
{
	char	*namefile[2];
	int		fd[4];
	t_bmpi	bmpi;
	t_bmpf	bmpf;

	namefile[0] = ft_strjoin(SCREEN_SAVE, "Screenshot_");
	namefile[1] = ft_itoa(time(NULL));
	namefile[0] = ft_strjoin1(namefile[0], namefile[1]);
	free(namefile[1]);
	namefile[0] = ft_strjoin1(namefile[0], ".bmp");
	fd[0] = open(namefile[0], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	free(namefile[0]);
	if (fd < 0)
		exit(EXIT_FAILURE);
	fd[1] = win.h * win.w;
	fd[2] = sizeof(t_img) * win.w;
	fd[3] = (4 - (fd[2] % 4)) % 4;
	bmp_file_header(&bmpf, fd, win.h);
	bmp_image_header(&bmpi, fd[1], win);
	write_header(fd[0], &bmpf, &bmpi);
	save_screen1(fd, pic, win.h);
	close(fd[0]);
}
