/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:08:46 by mray              #+#    #+#             */
/*   Updated: 2018/03/08 23:08:54 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arrow_keys(int key, void *parameters)
{
	t_params *para;

	para = (t_params *)parameters;
	if (key == 126)
		((t_gl *)para->p1)->live_trans[7]++;
	else if (key == 125)
		((t_gl *)para->p1)->live_trans[7]--;
	else if (key == 123)
		((t_gl *)para->p1)->live_trans[6]++;
	else if (key == 124)
		((t_gl *)para->p1)->live_trans[6]--;
	else
		return (0);
	return (1);
}

int	alpha_keys(int key, void *parameters)
{
	t_params *para;

	para = (t_params *)parameters;
	if (key == 53)
		exit(1);
	else if (key == 0)
		((t_gl *)para->p1)->live_trans[4]++;
	else if (key == 17)
		((t_gl *)para->p1)->live_trans[3]++;
	else if (key == 6)
		((t_gl *)para->p1)->live_trans[2]--;
	else if (key == 7)
		((t_gl *)para->p1)->live_trans[0]++;
	else if (key == 16)
		((t_gl *)para->p1)->live_trans[1]++;
	else
		return (0);
	return (1);
}

int	key_handler(int key, void *parameters)
{
	t_params *para;

	para = (t_params *)parameters;
	if (arrow_keys(key, parameters) || alpha_keys(key, parameters))
		draw(para);
	ft_putnbr(key);
	return (0);
}
