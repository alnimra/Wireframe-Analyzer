/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:00:41 by mray              #+#    #+#             */
/*   Updated: 2018/03/01 15:00:41 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	extrace_dim_data(t_gl *gl, int ints[3], char **line_of_data,
					char ***row_of_data)
{
	if ((*row_of_data))
		free_array((void **)(*row_of_data));
	(*row_of_data) = ft_strsplit((*line_of_data), ' ');
	if (ints[2] == -1)
	{
		ints[2] = get_elem_num((void **)(*row_of_data));
		gl->dim[0] = ints[2];
	}
	else
		ints[2] = get_elem_num((void **)(*row_of_data));
	if (ints[2] != gl->dim[0])
	{
		ft_putstr("Passed in data has a bad width\n");
		ft_putnbr(ints[2]);
		ft_putchar('\n');
		ft_putnbr(gl->dim[0]);
		ft_putchar('\n');
		exit(1);
	}
	if ((*line_of_data))
		ft_memdel((void **)&(*line_of_data));
	gl->dim[1]++;
}

void	get_dims_fdf_file(char *filename, t_gl *gl)
{
	int		ints[3];
	char	*line_of_data;
	char	**row_of_data;

	ints[0] = open(filename, O_RDONLY);
	if (ints[0] < 0)
	{
		ft_putstr("File opening error occured");
		exit(1);
	}
	gl->dim[1] = 0;
	ints[2] = -1;
	row_of_data = NULL;
	while ((ints[1] = get_next_line(ints[0], &line_of_data)) > 0)
		extrace_dim_data(gl, ints, &line_of_data, &row_of_data);
	close(ints[0]);
	free_array((void **)row_of_data);
	ft_memdel((void **)&line_of_data);
	if (gl->dim[0] != 0 && gl->dim[1] != 0)
		gl->live_trans[5] = get_scale_factor(gl);
	else
	{
		ft_putstr("Don't give a blank file...\n");
		exit(0);
	}
}
