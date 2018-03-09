/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:42:51 by mray              #+#    #+#             */
/*   Updated: 2018/03/08 15:43:00 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Credits to Po-Han Lin for EFLA_E
** http://www.edepot.com/algorithm.html
*/

void	y_longer(t_gl *gl, t_2dpt *pt_i, int para[7])
{
	if (para[3] > 0)
	{
		para[3] += pt_i->y;
		para[6] = 0x8000 + (pt_i->x << 16);
		while (pt_i->y <= para[3])
		{
			mlx_pixel_put(gl->lib, gl->surf, para[6] >> 16, pt_i->y, para[0]);
			para[6] += para[4];
			++pt_i->y;
		}
		return ;
	}
	para[3] += pt_i->y;
	para[6] = 0x8000 + (pt_i->x << 16);
	while (pt_i->y >= para[3])
	{
		mlx_pixel_put(gl->lib, gl->surf, para[6] >> 16, pt_i->y, para[0]);
		para[6] -= para[4];
		--pt_i->y;
	}
	return ;
}

void	y_not_longer(t_gl *gl, t_2dpt *pt_i, int para[7])
{
	if (para[3] > 0)
	{
		para[3] += pt_i->x;
		para[6] = 0x8000 + (pt_i->y << 16);
		while (pt_i->x <= para[3])
		{
			mlx_pixel_put(gl->lib, gl->surf, pt_i->x, para[6] >> 16, para[0]);
			para[6] += para[4];
			++pt_i->x;
		}
		return ;
	}
	para[3] += pt_i->x;
	para[6] = 0x8000 + (pt_i->y << 16);
	while (pt_i->x >= para[3])
	{
		mlx_pixel_put(gl->lib, gl->surf, pt_i->x, para[6] >> 16, para[0]);
		para[6] -= para[4];
		--pt_i->x;
	}
}

/*
** para[0] = color, para[1] = y_longer, para[2] = shortLen, para[3] = longLen,
** para[4] = decInc, para[5] = swap, para[6] = j
*/

void	efla_e(t_gl *gl, t_2dpt *pt_i, t_2dpt *pt_f, int color)
{
	int para[7];

	para[0] = color;
	para[1] = 0;
	para[2] = pt_f->y - pt_i->y;
	para[3] = pt_f->x - pt_i->x;
	if (abs(para[2]) > abs(para[3]))
	{
		para[5] = para[2];
		para[2] = para[3];
		para[3] = para[5];
		para[1] = 1;
	}
	if (para[3] == 0)
		para[4] = 0;
	else
		para[4] = (para[2] << 16) / para[3];
	if (para[1])
		return (y_longer(gl, pt_i, para));
	return (y_not_longer(gl, pt_i, para));
}
