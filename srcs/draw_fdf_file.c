/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 22:54:15 by mray              #+#    #+#             */
/*   Updated: 2018/03/08 22:54:24 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_wireframe_horz(char **rows_of_data[2], t_params *para,
						char **line_of_data, int ints[4])
{
	t_gl		*gl;
	t_pt_pairs	**pt_set;

	gl = para->p1;
	pt_set = para->p2;
	if (rows_of_data[1])
		free_array((void **)rows_of_data[1]);
	rows_of_data[1] = ft_strsplit(*line_of_data, ' ');
	ints[3] = 0;
	while (rows_of_data[1][ints[3] + 1])
	{
		set_3dpt(&((*pt_set)->pt3d1), ints[3], ints[2],
				ft_atoi(rows_of_data[1][ints[3]]));
		set_3dpt(&((*pt_set)->pt3d2), (ints[3] + 1), ints[2],
				ft_atoi(rows_of_data[1][ints[3] + 1]));
		draw_line(gl, pt_set,
				get_hex_color_from_string(rows_of_data[1][ints[3]]));
		ints[3]++;
	}
}

void	draw_wireframe_vert(char **rows_of_data[2], t_params *para,
						char **line_of_data, int ints[4])
{
	t_gl		*gl;
	t_pt_pairs	**pt_set;

	gl = para->p1;
	pt_set = para->p2;
	ints[3] = 0;
	while (ints[2] != 0 && rows_of_data[1][ints[3]])
	{
		set_3dpt(&((*pt_set)->pt3d1), ints[3], (ints[2] - 1),
				ft_atoi(rows_of_data[0][ints[3]]));
		set_3dpt(&((*pt_set)->pt3d2), ints[3], ints[2],
				ft_atoi(rows_of_data[1][ints[3]]));
		draw_line(gl, pt_set,
				get_hex_color_from_string(rows_of_data[1][ints[3]]));
		ints[3]++;
	}
	if (rows_of_data[0])
		free_array((void **)rows_of_data[0]);
	rows_of_data[0] = ft_strsplit(*line_of_data, ' ');
	if (*line_of_data)
		ft_memdel((void **)&(*line_of_data));
}

void	draw_wireframe(char **rows_of_data[2], t_params *para,
						char **line_of_data, int ints[4])
{
	draw_wireframe_horz(rows_of_data, para, &(*line_of_data), ints);
	draw_wireframe_vert(rows_of_data, para, &(*line_of_data), ints);
	ints[2]++;
}

void	draw_fdf_file(char *filename, t_gl *gl, t_pt_pairs **pt_set)
{
	int			ints[4];
	char		**rows_of_data[2];
	char		*line_of_data;
	t_params	*para;

	para = malloc(sizeof(t_params));
	para->p1 = gl;
	para->p2 = pt_set;
	ints[0] = open(filename, O_RDONLY);
	ints[2] = 0;
	rows_of_data[1] = NULL;
	rows_of_data[0] = NULL;
	if (ints[0] < 0)
	{
		ft_putstr("File opening error occured\n");
		exit(1);
	}
	while ((ints[1] = get_next_line(ints[0], &line_of_data)) > 0)
		draw_wireframe(rows_of_data, para, &line_of_data, ints);
	close(ints[0]);
	free_array((void **)rows_of_data[0]);
	free_array((void **)rows_of_data[1]);
	ft_memdel((void **)&line_of_data);
}
