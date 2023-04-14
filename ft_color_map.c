/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:51:00 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 15:59:28 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setup_color_pt3(t_map *m)
{
	if (m->setupcolor == 5)
	{
		m->color[0] = 0xff0000;
		m->color[15] = 0xffa500;
		m->color[30] = 0xffff00;
		m->color[45] = 0x00f000;
		m->color[60] = 0x0060ff;
		m->color[75] = 0x8b00f2;
		m->color[99] = 0xee82ee;
	}
	else if (m->setupcolor == 6)
	{
	m->color[0] = 0x000001;
	m->color[10] = 0x004C75;
	m->color[59] = 0x0094E3;
	m->color[61] = 0xe0cda9;
	m->color[63] = 0x72CC00;
	m->color[70] = 0x298000;
	m->color[78] = 0x4f3000;
	m->color[80] = 0xffffff;
	m->color[99] = 0xffffff;
	}
}

void	ft_setup_color_pt2(t_map *m)
{
	if (m->setupcolor == 4)
	{
		m->color[0] = 0x333333;
		m->color[99] = 0xffffff;
	}
	else
		ft_setup_color_pt3(m);
}

void	ft_setup_color_pt1(t_map *m)
{
	if (m->setupcolor == 0)
	{
		m->color[0] = 0x0066ff;
		m->color[99] = 0xff0000;
	}
	else if (m->setupcolor == 1)
	{
		m->color[0] = 0xff00ff;
		m->color[99] = 0x0070ff;
	}
	else if (m->setupcolor == 2)
	{
		m->color[0] = 0xff0000;
		m->color[99] = 0xffff00;
	}
	else if (m->setupcolor == 3)
	{
		m->color[0] = 0x00ff00;
		m->color[99] = 0xff00ff;
	}
	else
		ft_setup_color_pt2(m);
}
