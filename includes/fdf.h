/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:03:03 by mray              #+#    #+#             */
/*   Updated: 2018/02/26 14:03:03 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <time.h>
# define WIDTH 2048
# define HEIGHT 1728

typedef struct		s_3dpt
{
	int x;
	int y;
	int z;
}					t_3dpt;
t_3dpt				*create_3dpt(int x, int y, int z);
void				set_3dpt(t_3dpt **pt, int x, int y, int z);
typedef struct		s_2dpt
{
	int x;
	int y;
}					t_2dpt;
t_2dpt				*create_2dpt(int x, int y);
typedef struct		s_gl
{
	void	*lib;
	void	*surf;
	double	live_trans[9];
	int		dim[2];
}					t_gl;
t_gl				*create_gl(void *lib, void *surf);
typedef struct		s_pt_pairs
{
	t_2dpt	*pt2d1;
	t_2dpt	*pt2d2;
	t_3dpt	*pt3d1;
	t_3dpt	*pt3d2;
}					t_pt_pairs;
typedef struct		s_params
{
	void *p1;
	void *p2;
	void *p3;
}					t_params;
t_pt_pairs			*create_pt_pairs(t_2dpt *pt2d1, t_2dpt *pt2d2,
						t_3dpt *pt3d1, t_3dpt *pt3d2);
void				conv_3d_to_2d(t_gl *gl, t_2dpt **pt_2d, t_3dpt *pt_3d);
void				draw_line(t_gl *gl, t_pt_pairs **pt_set, int color);
void				draw_axis(t_gl *gl, t_pt_pairs **pt_set);
void				draw_trianglar_prism(t_gl *gl, t_pt_pairs **pt_set,
										int dim);
void				get_dims_fdf_file(char *filename, t_gl *gl);
void				draw_fdf_file(char *filename, t_gl *gl,
													t_pt_pairs **pt_set);
void				efla_e(t_gl *gl, t_2dpt *pt_i, t_2dpt *pt_f, int color);
int					get_elem_num(void **array);
int					get_scale_factor(t_gl *gl);
int					get_hex_color_from_string(char *str);
int					key_handler(int key, void *parameters);
void				draw(t_params *para);
#endif
