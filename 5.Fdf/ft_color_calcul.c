/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:56:24 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/09 19:28:06 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color(int nbr, t_map *m)
{
	int	tmp;

	tmp = nbr / 1048576;
	nbr = nbr - 1048576 * tmp;
	m->img.r = tmp * 16;
	tmp = nbr / 65536;
	nbr = nbr - 65536 * tmp;
	m->img.r += tmp;
	tmp = nbr / 4096;
	nbr = nbr - 4096 * tmp;
	m->img.g = tmp * 16;
	tmp = nbr / 256;
	nbr = nbr - 256 * tmp;
	m->img.g += tmp;
	tmp = nbr / 16;
	nbr = nbr - 16 * tmp;
	m->img.b = tmp * 16;
	m->img.b += nbr;
}

void	ft_draw(t_map *m, float x, float y, int color)
{
	unsigned long	pixel;

	x = roundf(x);
	y = roundf(y);
	ft_color(color, m);
	pixel = (y * m->img.size) + (x * 4);
	if (((unsigned long)(m->img.size) * m->winy) < pixel - 5 || x <= 0
		|| y <= 0 || y > m->y * m->winy || x > m->winx)
		return ;
	if (m->img.e == 1)
	{
		m->img.data[pixel + 0] = 0;
		m->img.data[pixel + 1] = m->img.r;
		m->img.data[pixel + 2] = m->img.g;
		m->img.data[pixel + 3] = m->img.b;
	}
	else if (m->img.e == 0)
	{
		m->img.data[pixel + 0] = m->img.b;
		m->img.data[pixel + 1] = m->img.g;
		m->img.data[pixel + 2] = m->img.r;
		m->img.data[pixel + 3] = 0;
	}
}

void	ft_tab_deg(t_map *m, int start, int end)
{
	int		i;
	float	pc;
	float	diff;
	int		color;
	t_map	c;

	ft_color(m->color[start], m);
	ft_color(m->color[end], &c);
	diff = end - start - 1;
	i = 0 ;
	while (i <= diff)
	{
		pc = ((i) / diff);
		color = roundf((m->img.r * (1 - pc)) + (c.img.r * pc)) * 65536;
		color += roundf((m->img.g * (1 - pc)) + (c.img.g * pc)) * 256;
		color += roundf((m->img.b * (1 - pc)) + (c.img.b * pc));
		m->color[start + i] = color;
		i++;
	}
}

void	ft_tab_color(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 101)
	{
		if (m->color[i] != 0)
		{
			j = i;
			i++;
			while (i <= 99 && m->color[i] == 0)
				i++;
			if (99 < i)
				return ;
			ft_tab_deg(m, j, i);
		}
		else
			i++;
	}
}

void	ft_init_color(t_map *m)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		m->color[i] = 0;
		i++;
	}
	if (m->setupcolor > 6)
		m->setupcolor = 0;
	ft_setup_color_pt1(m);
	ft_tab_color(m);
}
