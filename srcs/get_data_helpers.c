/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 22:47:01 by mray              #+#    #+#             */
/*   Updated: 2018/03/08 22:47:10 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_elem_num(void **array)
{
	int i;

	i = -1;
	while (array[++i])
		;
	return (i);
}

int		get_scale_factor(t_gl *gl)
{
	if (WIDTH / gl->dim[0] > HEIGHT / gl->dim[1])
		return (HEIGHT / gl->dim[1]);
	return (WIDTH / gl->dim[0]);
}

int		get_hex_color_from_string(char *str)
{
	char *str_color;

	if ((str_color = ft_strsplit(str, ',')[1]))
		return (ft_atoi_base(str_color + 2, 16));
	else
		return (0xFFFFFF);
}
