/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <latkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:57:12 by latkins           #+#    #+#             */
/*   Updated: 2021/03/13 12:26:28 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT1_H
# define MINIRT1_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <time.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line_bonus.h"
# include <stdio.h>
# include <limits.h>

# define ARG_ERR			"2 argvs max\n Use -save to make bmp"
# define TYP_ERR			"Unidentified file in configuration"
# define WOR_ERR			"Incorrect number of properties"
# define TRU_ERR			"The value must be positive number or float"
# define UNI_ERR			"The R and A must be unique properties"
# define VAL_ERR			"The value must be in the range - 1 to 1"
# define MAL_ERR			"Malloc error"
# define VEC_ERR			"Vector is not valid"
# define NVR_ERR			"The normal vector must be in the range -1 to 1"
# define FOV_ERR			"The Fov must be in the range 0 to 180"
# define INT_ERR			"The value must be positive int"
# define COL_ERR			"A color is defined by three ints from 0 to 255"
# define BMP_SUC			"Screenshots saved in ./Pictures/\n"
# define BMP_ERR			"Screenshot didn't save in ./Pictures/\n"
# define MIL_ERR			"Minilibx error"
# define SAV_ERR			"Use -save as 2nd arg to make bmp"
# define IMG_ERR			"Save image error"
# define FD1_ERR			"The path to configurates file must be valid"
# define EMP_ERR			"Empty file"

# define SCREEN_SAVE		"./Screenshots/"

# define EROR				-1
# define NORM				1
# define READY				0

# define TRUE				0
# define FALSE				-1

# define RT					1
# define RF					0

# define EPSILON			1.0e-6
# define MINT				1.0e-3

# define M1R				"R"
# define M1A				"A"
# define M1C				"c"
# define M1L				"l"
# define M1PL				"pl"
# define M1SP				"sp"
# define M1SQ				"sq"
# define M1CY				"cy"
# define M1TR				"tr"

# ifdef LINUX

#  define ESC				65307
#  define LEFT				65361
#  define RIGHT				65363
#  define KEY_SPACE			65289

# else

#  define ESC				53
#  define LEFT				123
#  define RIGHT				124
#  define KEY_SPACE			49

# endif

enum				e_objects
{
	PLANE,
	SPHERE,
	SQUARE,
	CYLINDER,
	TRIANGLE
};

typedef struct		s_cololor
{
	int r;
	int g;
	int b;
}					t_col;

typedef struct		s_vector
{
	double x;
	double y;
	double z;
}					t_vec;

typedef struct		s_sphere
{
	t_vec	poz;
	double	diam;
	t_col	col;
}					t_sp;

typedef struct		s_plane
{
	t_vec poz;
	t_vec dir;
	t_col col;
}					t_pl;

typedef struct		s_square
{
	t_vec	poz;
	t_vec	dir;
	double	h;
	t_col	col;
}					t_sq;

typedef struct		s_cylinder
{
	t_vec	poz;
	t_vec	dir;
	double	h;
	double	diam;
	t_col	col;
}					t_cy;

typedef struct		s_triangle
{
	t_vec poz;
	t_vec poz1;
	t_vec poz2;
	t_col col;
}					t_tr;

typedef struct		s_matrix
{
	double m[4][4];
}					t_matx;

union				u_figure
{
	t_sp sp;
	t_pl pl;
	t_sq sq;
	t_cy cy;
	t_tr tr;
};

typedef struct		s_intersection
{
	double			t;
	double			it;
	t_vec			poz;
	t_vec			center;
	t_col			col;
	t_vec			normal;
	t_vec			point;
	double			desc;
	double			desc1;
	double			i1;
	double			i2;
}					t_inter;

typedef struct		s_elements
{
	int					nbr;
	enum e_objects		vie;
	union u_figure		fige;
	struct s_elements	*next;
}					t_elem;

typedef struct		s_camera
{
	int				nbr;
	t_vec			poz;
	t_vec			dir;
	double			fov;
	struct s_camera	*next;
}					t_cam;

typedef struct		s_light
{
	t_vec			poz;
	t_col			col;
	double			its;
	int				nbr;
	struct s_light	*next;
}					t_lgt;

typedef struct		s_window
{
	int w;
	int h;
}					t_win;

typedef struct		s_ambul
{
	double	al;
	t_col	col;
}					t_am;

typedef struct		s_minilibx
{
	void	*param;
	int		wmax;
	int		hmax;
	void	*op;
	void	*pic;
	char	*addr;
	int		bbp;
	int		size;
	int		end;
}					t_mlx;

typedef struct		s_addr
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_img;

typedef struct		s_minirt
{
	t_win	coor;
	t_am	am;
	t_cam	*cam;
	t_lgt	*lgt;
	t_elem	*elem;
	t_mlx	mlx;
	int		func;
	size_t	num_line;
	t_img	**pic;
	int		pov;
	int		rr;
	int		camer;
	int		camer1;
	int		key;
	int		yy;
	int		okc;
	int		okr;
	int		oka;
}					t_mrt;

typedef struct		s_bmp_image
{
	unsigned int	head_size;
	unsigned int	width;
	unsigned int	height;
	int				plane;
	int				bit_count;
	unsigned int	compres;
	unsigned int	imsize;
	unsigned int	w_res;
	unsigned int	h_res;
	unsigned int	color;
	unsigned int	imp_col;
}					t_bmpi;

typedef struct		s_bmp_file
{
	unsigned char	bt[2];
	int				file_size;
	int				reser;
	int				reser1;
	unsigned int	offset;
}					t_bmpf;

typedef union		u_col
{
	int				x;
	unsigned char	pad[4];
}					t_intimg;

typedef void		(*t_func)(t_mrt *, char **);

int					ac3(t_mrt *gen);
int					print_error(char *err, int l);
int					ft_lightstr(char *s1, char *s2, int nb);
int					int_fov(char *s);
int					parcing(char *line, t_mrt *gen);
void				initt(t_mrt *gen);
int					numbers(char *s);
int					count_words2(char **map, int s, t_mrt *gen);
void				free_map(char **map);
int					ft_gain1(int i, t_mrt *gen, char **map);
int					ft_gain2(int i, t_elem **elem, t_mrt *gen, char **map);
int					ft_gain3(int i, t_vec *ray, t_elem *obj, t_inter *intt);
void				resol_er1(t_mrt *gen);
void				resol_er(t_mrt *gen);
void				resol_er2(t_mrt *gen);
int					am_cor(t_mrt *gen, char **map);
int					resol_er3(t_mrt *gen);
int					resol_er4(t_mrt *gen);
int					resol_er5(t_mrt *gen);
int					resol_er6(t_mrt *gen);
int					resol_er7(t_mrt *gen);
int					resol_er8(t_mrt *gen);
int					resol_er9(t_mrt *gen);
int					resol_er10(t_mrt *gen);
int					camera1(t_mrt *gen, char **map, t_cam *cam);
t_cam				selcam(t_mrt gen);
void				cust_cum(int key, t_mrt *gen);
void				link_cam(t_cam *cam, t_cam **caz, int nb);
int					good_col(t_col *col);
t_col				col_init(char **sub);
int					check_col(char *s);
int					corona(char *s, t_col *col, t_mrt *gen);
void				link_lights(t_lgt *lig, t_lgt **lif);
void				free_light(t_lgt **light);
void				free_cam(t_cam **cam);
void				free_elem(t_elem **elem);
void				normalization(t_vec *a);
t_vec				multiply_atvec(t_vec v, t_matx m);
t_vec				cross_product(t_vec *a, t_vec *b);
double				dot_product(t_vec a, t_vec b);
t_vec				sub_product(t_vec a, t_vec b);
int					lights(t_mrt *gen, char **map);
int					camera(t_mrt *gen, char **map);
int					ambient_lightning(t_mrt *gen, char **map);
int					resolution(t_mrt *gen, char **map);
int					sp_go(t_elem **elem, t_mrt *gen, char **map);
int					pl_go(t_elem **elem, t_mrt *gen, char **map);
int					sq_go(t_elem **elem, t_mrt *gen, char **map);
int					cy_go(t_elem **elem, t_mrt *gen, char **map);
int					tr_go(t_elem **elem, t_mrt *gen, char **map);
void				link_sp(t_elem **elem, t_mrt *gen, t_sp sp);
void				link_pl(t_elem **elem, t_mrt *gen, t_pl pl);
void				link_sq(t_elem **elem, t_mrt *gen, t_sq sq);
void				link_cy(t_elem **elem, t_mrt *gen, t_cy cy);
void				link_tr(t_elem **elem, t_mrt *gen, t_tr tr);
t_vec				new_vector(double x, double y, double z);
int					good_vec(t_vec *vic);
int					check_vec(char *s);
t_vec				vec_init(char **sub);
int					gektor(char *s, t_vec *vec, t_mrt *gen);
t_vec				add_product(t_vec a, t_vec b);
t_vec				multiplay_product(t_vec a, double d);
double				sent_sq(t_vec *a);
void				zero_vector(t_vec *vec);
t_vec				proportionvec(t_col a, t_vec h);
t_vec				add_colorsvec(t_vec a, t_vec b);
t_vec				multiplay_productcol(t_col *a, double d);
double				chek_l(double v);
t_col				add_colors(t_col a, t_col v);
t_col				proportion(t_col a, t_col v);
t_col				int_tocol(int r, int g, int b);
void				init_color(t_col *col);
t_col				multi_doub(t_col *col, double v);
int					close_window(t_mrt *gen);
int					keyhook(int key, t_mrt *gen);
int					calc_quadratic(double *d, t_inter *intt);
t_vec				points_square(t_sq sq);
void				choose_sign(t_vec nor, t_inter *intt, t_vec pozp);
void				zero_inter(t_inter *inter, t_vec ori);
void				my_mlx_pixel_put(t_mlx *mlx, int x, int y, int col);
int					shadow(t_elem *obj, t_vec lit_ray, t_inter *inter);
int					exic_cy(double *d, t_cy cy, t_vec *ray, t_inter *intt);
void				normalfor_cy(t_cy cy, t_inter *intt);
void				mark_candidates(double *t, t_vec *ray,
					t_cy cy, t_inter *intt);
int					inside_out_test(t_tr tr, t_inter *intt);
int					sp_in(t_vec *ray, t_elem *obj, t_inter *intt);
int					pl_in(t_vec *ray, t_elem *obj, t_inter *intt);
int					sq_in(t_vec *ray, t_elem *obj, t_inter *intt);
int					cy_in(t_vec *ray, t_elem *obj, t_inter *intt);
int					tr_in(t_vec *ray, t_elem *obj, t_inter *intt);
void				save_screen(t_img **pic, t_win win);
int					color_toint(t_col col);
int					save_img(t_mrt *gen);
void				find_inter(t_mrt *gen, t_vec *ray,
					t_inter *inter, t_cam *cam);
t_vec				init_ray(int *y, t_win won, t_cam cam, t_inter *inter);
int					comp_lighting(t_mrt *gen, t_inter inter);
void				raytracing(t_mrt *gen);
void				normalfor_tria(t_vec *e, t_inter *intt,
					t_tr tr, t_vec *ray);
t_vec				multiply_by_matrix(t_vec p, t_matx m);
t_matx				lookat(t_vec at);
t_col				pad_col(int color);
t_img				**new_addr(t_win win);
t_img				ad_int(int col);
void				free_pic(t_img **pic, int hei);
t_vec				ft_normal(t_vec nor, t_vec ray);
void				init_inter(t_inter *gg, t_mrt *y);
void				ft_lstadd_front1(t_elem **lst, t_elem *new);
int					sq_pl(t_vec *ray, t_elem *obj, t_inter *intt);
t_matx				camera_rotat(t_vec za, t_vec xa, t_vec ya);

#endif
