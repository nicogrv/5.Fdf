/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:09:00 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/09 19:57:26 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map_x(int x, int y, t_map *m)
{
	m->line.ax = m->m[y][x].x;
	m->line.ay = m->m[y][x].y;
	m->line.bx = m->m[y][x + 1].x;
	m->line.by = m->m[y][x + 1].y;
	m->line.hcolor1 = m->m[y][x].h;
	m->line.hcolor2 = m->m[y][x + 1].h;
	ft_ligne(m);
}

void	ft_print_map_y(int x, int y, t_map *m)
{
	m->line.ax = m->m[y][x].x;
	m->line.ay = m->m[y][x].y;
	m->line.bx = m->m[y + 1][x].x;
	m->line.by = m->m[y + 1][x].y;
	m->line.hcolor1 = m->m[y][x].h;
	m->line.hcolor2 = m->m[y + 1][x].h;
	ft_ligne(m);
}

void	ft_print_map(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			if (x < m->x - 1)
				ft_print_map_x(x, y, m);
			if (y < m->y -1)
				ft_print_map_y(x, y, m);
			x++;
		}
		y++;
		x = 0;
	}
}
