/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:02:49 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 22:26:43 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hauteur(t_map *m)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].h = m->m[y][x].z ;
			if (m->m[y][x].h < m->minh)
			{
				m->minh = m->m[y][x].h;
			}
			if (m->maxh < m->m[y][x].h)
				m->maxh = m->m[y][x].h;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_rota(t_map *m)
{
	float	tmpx;
	int		x;
	int		y;

	x = 0;
	y = 0;
	m->varcos = cos(m->r / 57.2958);
	m->varsin = sin(m->r / 57.2958);
	while (y < m->y)
	{
		while (x < m->x)
		{
			tmpx = m->m[y][x].x;
			m->m[y][x].x = m->m[y][x].x * m->varcos + m->m[y][x].y * -m->varsin;
			m->m[y][x].y = tmpx * m->varsin + m->m[y][x].y * m->varcos;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_incl(t_map *m)
{
	int		x;
	int		y;
	float	varcos;
	float	varsin;

	x = 0;
	y = 0;
	varcos = cos(m->i / 57.2958);
	varsin = sin(m->i / 57.2958);
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].y = m->m[y][x].y * varsin;
			m->m[y][x].y += (m->m[y][x].z * m->hauteur) * m->z * -varcos;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_centre(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = m->m[y][x].x - m->x * m->z / 2;
			m->m[y][x].y = m->m[y][x].y - m->y * m->z / 2;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_move(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = (m->m[y][x].x + m->winx / 2) + m->movex;
			m->m[y][x].y = (m->m[y][x].y + m->winy / 2) + m->movey;
			x++;
		}
		y++;
		x = 0;
	}
}
