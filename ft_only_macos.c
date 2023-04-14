/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_macos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:44:01 by nicolasgriv       #+#    #+#             */
/*   Updated: 2023/01/06 19:51:32 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error_malloc_copy(t_map *m, int index, int y)
{
	ft_error_malloc_init(m->y - 1, m);
	if (index == 1)
	{
		while (y != -1)
		{
			free(m->m[y]);
			y--;
		}
		free(m->m);
	}
	mlx_destroy_image(m->mlx, m->img.i);
	mlx_destroy_window(m->mlx, m->mlx_win);
	free(m->mlx);
	return (-1);
}

void	ft_key_pt3(int keycode, t_map *m)
{
	if (keycode == TOUCH_S)
			m->movey = m->movey - 30;
	else if (keycode == TOUCH_D)
			m->movex = m->movex + 30;
	else if (keycode == TOUCH_A)
			m->movex = m->movex - 30;
	else if (keycode == TOUCH_C)
			m->setupcolor += 1;
	else if (keycode == ESC || keycode == -16779872)
	{
		ft_free_map(m, 1);
		mlx_destroy_image(m->mlx, m->img.i);
		mlx_destroy_window(m->mlx, m->mlx_win);
		free(m->mlx);
		exit(0);
	}
	else if (keycode == TOUCH_I)
			m->verifmonitor *= -1;
	ft_key_pt4(keycode, m);
}

int	ft_cross_close(t_map *m)
{
	ft_free_map(m, 1);
	mlx_destroy_image(m->mlx, m->img.i);
	mlx_destroy_window(m->mlx, m->mlx_win);
	free(m->mlx);
	exit(0);
	return (1);
}

int	ft_init_mlxpt2(t_map *m)
{
	char	*data;

	data = mlx_get_data_addr(m->img.i, &m->img.p, &m->img.size, &m->img.e);
	m->img.data = data;
	if (m->img.data == NULL)
	{
		mlx_destroy_image(m->mlx, m->img.i);
		mlx_destroy_window(m->mlx, m->mlx_win);
		return (ft_free_map(m, 2), free(m->mlx), 1);
	}
	return (0);
}

int	ft_init_mlx(t_map *m)
{
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		return (ft_free_map(m, 2), 1);
	m->mlx_win = mlx_new_window(m->mlx, m->winx, m->winy, "FDF");
	if (m->mlx_win == NULL)
	{
		return (ft_free_map(m, 2), free(m->mlx), 1);
	}
	m->img.i = mlx_new_image(m->mlx, m->winx, m->winy);
	if (m->img.i == NULL)
	{
		mlx_destroy_window(m->mlx, m->mlx_win);
		return (ft_free_map(m, 2), free(m->mlx), 1);
	}
	if (ft_init_mlxpt2(m) == -1)
		return (-1);
	return (0);
}