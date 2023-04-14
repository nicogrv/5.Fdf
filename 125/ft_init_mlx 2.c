/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:11:56 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/06 14:19:03 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_mlxpt2(t_map *m)
{
	char	*data;

	data = mlx_get_data_addr(m->img.i, &m->img.p, &m->img.size, &m->img.e);
	m->img.data = data;
	if (m->img.data == NULL)
	{
		mlx_destroy_image(m->mlx, m->img.i);
		mlx_destroy_window(m->mlx, m->mlx_win);
		mlx_destroy_display(m->mlx);
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
		mlx_destroy_display(m->mlx);
		return (ft_free_map(m, 2), free(m->mlx), 1);
	}
	m->img.i = mlx_new_image(m->mlx, m->winx, m->winy);
	if (m->img.i == NULL)
	{
		mlx_destroy_window(m->mlx, m->mlx_win);
		mlx_destroy_display(m->mlx);
		return (ft_free_map(m, 2), free(m->mlx), 1);
	}
	if (ft_init_mlxpt2(m) == -1)
		return (-1);
	return (0);
}
