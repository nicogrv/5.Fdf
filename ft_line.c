/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 22:25:36 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line_direction_pt1(float dx, float unity, float tmp, t_map *m)
{
	int	i;

	i = 0;
	if (m->line.reverse == 1)
	{
		tmp = m->line.hcolor1;
		m->line.hcolor1 = m->line.hcolor2;
		m->line.hcolor2 = tmp;
	}
	while (i++ < dx)
	{
		ft_draw(m, m->line.ax, m->line.ay, ft_color_line(dx, i, m));
		m->line.ay = m->line.ay + unity;
		m->line.ax++;
	}
}

void	ft_line_direction_pt2(float dy, float unity, float tmp, t_map *m)
{
	int	i;

	i = 0;
	if (m->line.reverse == 1)
	{
		tmp = m->line.hcolor1;
		m->line.hcolor1 = m->line.hcolor2;
		m->line.hcolor2 = tmp;
	}
	while (i < dy)
	{
		ft_draw(m, m->line.ax, m->line.ay, ft_color_line(dy, i, m));
		m->line.ay++;
		m->line.ax = m->line.ax + (1 / unity);
		i++;
	}
}

void	ft_line_direction_pt3(float dy, float unity, float tmp, t_map *m)
{
	int	i;

	i = 0;
	if (m->line.reverse == 1)
	{			
		tmp = m->line.hcolor1;
		m->line.hcolor1 = m->line.hcolor2;
		m->line.hcolor2 = tmp;
	}
	while (i > dy)
	{
		ft_draw(m, m->line.ax, m->line.ay, ft_color_line(dy, i, m));
		m->line.ay--;
		m->line.ax = m->line.ax - (1 / unity);
		i--;
	}
}

void	ft_reverse_direction(float tmp, t_map *m)
{
		tmp = m->line.bx;
		m->line.bx = m->line.ax;
		m->line.ax = tmp;
		tmp = m->line.by;
		m->line.by = m->line.ay;
		m->line.ay = tmp;
		m->line.reverse = 1;
}

void	ft_ligne(t_map *m)
{
	float	dx;
	float	dy;
	float	unity;
	float	tmp;

	tmp = 0;
	if ((m->line.ax < 0 || m->line.ay < 0 || m->line.ax > m->winx
			|| m->line.ay > m->winy) && (m->line.bx < 0 || m->line.by < 0
			|| m->line.bx > m->winx || m->line.by > m->winy))
		return ;
	m->line.reverse = 0;
	if (m->line.bx < m->line.ax)
		ft_reverse_direction(tmp, m);
	dx = (float)m->line.bx - (float)m->line.ax;
	dy = (float)m->line.by - (float)m->line.ay;
	unity = dy / dx;
	if (dy == 0 || (0 < unity && unity < 1) || (-1 <= unity && unity < 0))
		ft_line_direction_pt1(dx, unity, tmp, m);
	else if (1 <= unity)
		ft_line_direction_pt2(dy, unity, tmp, m);
	else
		ft_line_direction_pt3(dy, unity, tmp, m);
}
