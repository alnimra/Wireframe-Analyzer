/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:57:35 by mray              #+#    #+#             */
/*   Updated: 2018/02/26 13:57:35 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_params *para)
{
	mlx_clear_window(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf);
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 0, 0,
				0xFFFFFF, "[x] X Rot: ");
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 100, 0,
				0xFFFFFF, ft_itoa((int)((t_gl *)para->p1)->live_trans[0]));
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 0, 30,
				0xFFFFFF, "[y] Y Rot: ");
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 100, 30,
				0xFFFFFF, ft_itoa((int)((t_gl *)para->p1)->live_trans[1]));
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 0, 60,
				0xFFFFFF, "[z] Z Rot: ");
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 100, 60,
				0xFFFFFF, ft_itoa((int)((t_gl *)para->p1)->live_trans[2]));
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 0, 90,
				0xFFFFFF, "[a] Proj Angle: ");
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 160, 90,
				0xFFFFFF, ft_itoa((int)((t_gl *)para->p1)->live_trans[4]));
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 0, 120,
				0xFFFFFF, "[t] Trans Angle: ");
	mlx_string_put(((t_gl *)para->p1)->lib, ((t_gl *)para->p1)->surf, 160, 120,
				0xFFFFFF, ft_itoa((int)((t_gl *)para->p1)->live_trans[3]));
	draw_axis((t_gl *)para->p1, (t_pt_pairs **)para->p2);
	draw_fdf_file((char *)para->p3, (t_gl *)para->p1,
				((t_pt_pairs **)para->p2));
}

int		mouse_handler(int key, int x, int y, void *parameters)
{
	t_params *para;

	para = (t_params *)parameters;
	ft_putnbr(x);
	ft_putnbr(y);
	if (key == 5)
	{
		((t_gl *)para->p1)->live_trans[8] += .1;
		draw(para);
	}
	if (key == 4)
	{
		((t_gl *)para->p1)->live_trans[8] -= .1;
		draw(para);
	}
	ft_putnbr(key);
	return (0);
}

int		main(int argc, char **argv)
{
	t_gl		*gl;
	void		*mlx;
	void		*window;
	t_pt_pairs	*pt_set;
	t_params	*para;

	para = malloc(sizeof(t_params));
	if (argc == 2)
	{
		mlx = mlx_init();
		window = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF Wireframe Visualizer");
		gl = create_gl(mlx, window);
		pt_set = create_pt_pairs(create_2dpt(0, 0), create_2dpt(0, 0),
								create_3dpt(0, 0, 0), create_3dpt(0, 0, 0));
		para->p1 = gl;
		para->p2 = &pt_set;
		para->p3 = argv[1];
		get_dims_fdf_file(argv[1], gl);
		draw_fdf_file(argv[1], gl, &pt_set);
		mlx_hook(gl->surf, 2, 0, key_handler, para);
		mlx_hook(gl->surf, 4, 0, mouse_handler, para);
		mlx_loop(gl->lib);
	}
}
