/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:01:20 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 20:25:59 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_map(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	m->m = malloc(sizeof(t_pixel *) * (m->y));
	if (!(m->m))
		return (ft_error_malloc_copy(m, 0, y));
	while (y < m->y)
	{
		m->m[y] = ft_calloc(sizeof(t_pixel), (m->x));
		if (!(m->m[y]))
			return (ft_error_malloc_copy(m, 1, y));
		while (x < m->x)
		{
			m->m[y][x].y = y * m->z;
			m->m[y][x].x = x * m->z;
			m->m[y][x].z = m->initm[y][x].z ;
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}
