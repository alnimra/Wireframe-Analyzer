/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:38:19 by mray              #+#    #+#             */
/*   Updated: 2018/02/26 16:38:19 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3dpt		*create_3dpt(int x, int y, int z)
{
	t_3dpt *tmp;

	tmp = ft_memalloc(sizeof(t_3dpt));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	return (tmp);
}

void		set_3dpt(t_3dpt **pt, int x, int y, int z)
{
	(*pt)->x = x;
	(*pt)->y = y;
	(*pt)->z = z;
}

t_2dpt		*create_2dpt(int x, int y)
{
	t_2dpt *tmp;

	tmp = ft_memalloc(sizeof(t_2dpt));
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

t_gl		*create_gl(void *lib, void *surf)
{
	t_gl	*tmp;
	int		i;

	tmp = ft_memalloc(sizeof(t_gl));
	tmp->lib = lib;
	tmp->surf = surf;
	i = -1;
	while (++i < 9)
		tmp->live_trans[i] = 0;
	tmp->live_trans[3] = 30;
	tmp->live_trans[4] = 120;
	tmp->live_trans[8] = 1;
	return (tmp);
}

t_pt_pairs	*create_pt_pairs(t_2dpt *pt2d1, t_2dpt *pt2d2, t_3dpt *pt3d1,
							t_3dpt *pt3d2)
{
	t_pt_pairs *tmp;

	tmp = ft_memalloc(sizeof(t_pt_pairs));
	tmp->pt2d1 = pt2d1;
	tmp->pt2d2 = pt2d2;
	tmp->pt3d1 = pt3d1;
	tmp->pt3d2 = pt3d2;
	return (tmp);
}
