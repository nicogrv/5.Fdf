/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:18:38 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/06 14:23:16 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_monitoring_display_info_pt3(t_map *m)
{
	int		y;
	char	*w;
	char	*x;

	y = m->winy - 13;
	w = m->mlx_win;
	x = m->mlx;
	mlx_string_put(x, w, 5, y - 13 * 12, 0xffffff, " WASD   |  MOVE");
	mlx_string_put(x, w, 5, y - 13 * 11, 0xffffff, "<- ->   |  ROTATE ");
	mlx_string_put(x, w, 5, y - 13 * 10, 0xffffff, " v ^    |  INCLINATION ");
	mlx_string_put(x, w, 5, y - 13 * 9, 0xffffff, " -  +   |  RELIEF DOWN/UP");
	mlx_string_put(x, w, 5, y - 13 * 8, 0xffffff, "1 2 3 4 |  PREPOSITION");
	mlx_string_put(x, w, 5, y - 13 * 7, 0xffffff, " 5      |  ANNIMATION");
	mlx_string_put(x, w, 5, y - 13 * 6, 0xffffff, " X  C   |  CHANGE COLOR");
	mlx_string_put(x, w, 5, y - 13 * 5, 0xffffff, " N  M   |  CHANGE MAP ");
	mlx_string_put(x, w, 5, y - 13 * 4, 0xffffff, " I      |  INFO OM/OFF ");
	mlx_string_put(x, w, 5, y - 13 * 3, 0xffffff, " P      |  PROJ ISO/PARA ");
	mlx_string_put(x, w, 5, y - 13 * 2, 0xffffff, " ESC    |  EXIT");
	mlx_string_put(x, w, 5, y - 13 * 1, 0xffffff, "RIGHT CLICK x2 |  MOVE");
}
