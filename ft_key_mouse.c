/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:07:05 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/06 19:45:00 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mouse_move(int x, int y, t_map *m)
{
	static int	x1;
	static int	y1;

	if (m->mouse_move == 1)
	{
		ft_clean(m);
		m->mouse_move = 0;
		m->r += (x - x1) / 30;
		m->i += (y - y1) / 30;
		ft_all(m);
	}
	else
	{
		m->mouse_move = 1;
		x1 = x;
		y1 = y;
	}
}

int	ft_zoom(int keycode, int x, int y, t_map *m)
{
	if (keycode != 1)
		ft_clean(m);
	if (keycode == 5)
		m->z -= m->z * 0.2;
	else if (keycode == 4)
		m->z += m->z * 0.2;
	else if (keycode == 1)
	{
		ft_mouse_move(x, y, m);
		return (1);
	}	
	ft_all(m);
	return (1);
}

void	ft_key_pt2(int keycode, t_map *m)
{
	if (keycode == TOUCH_ONE && m->verifprojection == 1)
	{
		m->r = 0;
		m->i = 0;
	}
	else if (keycode == TOUCH_TOW && m->verifprojection == 1)
	{
		m->i = 90;
		m->r = 0;
	}
	else if (keycode == TOUCH_THREE && m->verifprojection == 1)
	{
		m->r = 45;
		m->i = 20;
	}
	else if (keycode == TOUCH_FOUR && m->verifprojection == 1)
	{
		m->r = -45;
		m->i = 20;
	}
	else if (keycode == TOUCH_FIVE && m->verifprojection == 1)
		ft_annimation(m);
	else if (keycode == TOUCH_W)
			m->movey = m->movey + 30;
}

int	ft_key(int keycode, t_map *m)
{
	if (keycode == TOUCH_UPARROW && m->verifprojection == 1)
			m->i = m->i + 5;
	else if (keycode == TOUCH_DOWNARROW && m->verifprojection == 1)
			m->i = m->i - 5;
	else if (keycode == TOUCH_LEFTARROW)
			m->r = m->r - 5;
	else if (keycode == TOUCH_RIGHTARROW)
			m->r = m->r + 5;
	else if (keycode == TOUCH_PLUS)
	{
		m->hauteur = m->hauteur + m->hauteur * 0.3;
		m->minh = 0;
		m->maxh = 0;
	}
	else if (keycode == TOUCH_MOINS)
	{
		m->minh = 0;
		m->maxh = 0;
		m->hauteur = m->hauteur - m->hauteur * 0.3;
	}
	ft_key_pt2(keycode, m);
	ft_key_pt3(keycode, m);
	ft_clean(m);
	ft_all(m);
	return (1);
}
