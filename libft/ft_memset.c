/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:20:15 by mray              #+#    #+#             */
/*   Updated: 2018/02/19 16:20:19 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	byte;
	char	*b_ptr;

	byte = -1;
	b_ptr = b;
	while (++byte < len)
		*(b_ptr + byte) = c;
	return (b);
}
