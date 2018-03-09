/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dDraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:15:35 by mray              #+#    #+#             */
/*   Updated: 2018/02/26 15:15:35 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_axis(t_gl *gl, t_pt_pairs **pt_set)
{
	set_3dpt(&((*pt_set)->pt3d1), 0, 0, 0);
	set_3dpt(&((*pt_set)->pt3d2), 0, 0, 100);
	draw_line(gl, pt_set, 0xFFFFFF);
	set_3dpt(&((*pt_set)->pt3d2), 100, 0, 0);
	draw_line(gl, pt_set, 0xFFFFFF);
	set_3dpt(&((*pt_set)->pt3d2), 0, 100, 0);
	draw_line(gl, pt_set, 0xFFFFFF);
}

void	draw_line(t_gl *gl, t_pt_pairs **pt_set, int color)
{
	conv_3d_to_2d(gl, &(*pt_set)->pt2d1, (*pt_set)->pt3d1);
	conv_3d_to_2d(gl, &(*pt_set)->pt2d2, (*pt_set)->pt3d2);
	efla_e(gl, (*pt_set)->pt2d1, (*pt_set)->pt2d2, color);
}

void	zoom_and_shift_coords(t_gl *gl, t_2dpt **pt_2d, t_3dpt *pt_3d,
								double ts[5])
{
	(*pt_2d)->x = (pt_3d->x * cos(ts[0]) + pt_3d->y * cos(ts[0] + ts[1]) +
					pt_3d->z * cos(ts[0] - ts[1])) *
					gl->live_trans[8];
	(*pt_2d)->y = (pt_3d->x * sin(ts[0]) + pt_3d->y * sin(ts[0] + ts[1]) +
					pt_3d->z * sin(ts[0] - ts[1])) *
					gl->live_trans[8];
	(*pt_2d)->x +=
		(gl->dim[0] * (gl->live_trans[5]) / 2) + (gl->live_trans[6] * 5);
	(*pt_2d)->y +=
		(gl->dim[1] * (gl->live_trans[5]) / 2) + (gl->live_trans[7] * 5);
}

void	conv_3d_to_2d(t_gl *gl, t_2dpt **pt_2d, t_3dpt *pt_3d)
{
	double	ts[5];
	int		store_coord[3];

	ts[0] = 0.0174533 * gl->live_trans[3];
	ts[1] = 0.0174533 * gl->live_trans[4];
	ts[2] = 0.017453 * gl->live_trans[0];
	ts[3] = 0.017453 * gl->live_trans[1];
	ts[4] = 0.017453 * gl->live_trans[2];
	pt_3d->x *= gl->live_trans[5] / 2;
	pt_3d->y *= gl->live_trans[5] / 2;
	pt_3d->z *= gl->live_trans[5] / 2;
	store_coord[0] = pt_3d->x;
	pt_3d->x = store_coord[0] * cos(ts[4]) - pt_3d->y * sin(ts[4]);
	pt_3d->y = store_coord[0] * sin(ts[4]) + pt_3d->y * cos(ts[4]);
	store_coord[1] = pt_3d->y;
	pt_3d->y = store_coord[1] * cos(ts[2]) - pt_3d->z * sin(ts[2]);
	pt_3d->z = store_coord[1] * sin(ts[2]) + pt_3d->z * cos(ts[2]);
	store_coord[2] = pt_3d->z;
	pt_3d->z = store_coord[2] * cos(ts[3]) - pt_3d->x * sin(ts[3]);
	pt_3d->x = store_coord[2] * sin(ts[3]) + pt_3d->x * cos(ts[3]);
	zoom_and_shift_coords(gl, pt_2d, pt_3d, ts);
}
