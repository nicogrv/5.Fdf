/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:11:57 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/06 19:43:51 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_map *m, int exit)
{
	int	y;

	y = 0;
	while (y < m->y)
	{
		if (exit == 1 || exit == 0)
			free(m->m[y]);
		if (exit == 1 || exit == 2)
			free(m->initm[y]);
		y++;
	}
	if (exit == 1 || exit == 0)
		free(m->m);
	if (exit == 1 || exit == 2)
		free(m->initm);
}

void	ft_clean_mac(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < m->winx)
	{
		while (x < m->winy)
		{
			ft_draw(m, x, y, 0);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img.i, 0, 0);
}

void	ft_clean(t_map *m)
{
	if (OS == 1)
		ft_clean_mac(m);
	else
	{
		mlx_destroy_image(m->mlx, m->img.i);
		m->img.i = mlx_new_image(m->mlx, m->winx, m->winy);
	}
	ft_free_map(m, 0);
}

int	ft_error_malloc_init(int y, t_map *m)
{
	if (y != 0)
	{	
		while (y != -1)
		{
			free(m->initm[y]);
			y--;
		}
	}
	free(m->initm);
	return (-1);
}
