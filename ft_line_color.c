/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:34:31 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 14:40:54 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color_line_up(float nbpix, float pospix, float deltah, t_map *m)
{
	float	tmp;

	if (nbpix < 0)
			nbpix *= -1;
	if (pospix < 0)
			pospix *= -1;
	tmp = 100 * (m->line.hcolor2 - m->minh) / deltah;
	tmp -= 100 * (m->line.hcolor1 - m->minh) / deltah;
	tmp /= nbpix;
	if (0 > (int)((100 * (m->line.hcolor1 - m->minh) / deltah) + tmp * pospix))
		return (m->color[0]);
	if (99 < (int)((100 * (m->line.hcolor1 - m->minh) / deltah) + tmp * pospix))
		return (m->color[99]);
	tmp = ((100 * (m->line.hcolor1 - m->minh) / deltah) + tmp * pospix);
	return (m->color[(int)tmp]);
}

int	ft_color_line_down(float nbpix, float pospix, float deltah, t_map *m)
{
	float	tmp;

	tmp = 100 * (m->line.hcolor1 - m->minh) / deltah;
	tmp -= 100 * (m->line.hcolor2 - m->minh) / deltah;
	tmp /= nbpix;
	if (0 > (int)((100 * (m->line.hcolor1 - m->minh) / deltah) - tmp * pospix))
		return (m->color[0]);
	if (99 < (int)((100 * (m->line.hcolor1 - m->minh) / deltah) - tmp * pospix))
		return (m->color[99]);
	tmp = ((100 * (m->line.hcolor1 - m->minh) / deltah) - tmp * pospix);
	return (m->color[(int)tmp]);
}

int	ft_color_line(float nbpix, float pospix, t_map *m)
{
	float	tmp;
	float	deltah;

	deltah = (float)m->maxh - (float)m->minh;
	if (deltah == 0)
		deltah = 1;
	if (m->line.hcolor1 < m->line.hcolor2)
		return (ft_color_line_up(nbpix, pospix, deltah, m));
	else if (m->line.hcolor1 > m->line.hcolor2)
		return (ft_color_line_down(nbpix, pospix, deltah, m));
	else
	{
		tmp = (100 * (m->line.hcolor2 - m->minh) / deltah);
		if (tmp == 100)
			tmp -= 1;
		return (m->color[(int)tmp]);
	}
}
