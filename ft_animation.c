/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:13:13 by ngriveau          #+#    #+#             */
/*   Updated: 2023/04/14 14:41:19 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_annimationpt2(t_map *m)
{
	int	i;

	i = -1;
	while (++i < 360 / 3)
	{
		m->i += 0.3;
		m->r += 3;
		ft_clean(m);
		ft_all(m);
	}
	i = -1;
	while (++i < 360 / 3)
	{
		m->i -= 0.3;
		m->r += 3;
		ft_clean(m);
		ft_all(m);
	}
}

void	ft_annimation(t_map *m)
{
	int	inc;
	int	rot;

	inc = m->i;
	rot = m->r;
	m->i = 0;
	m->r = 0;
	ft_annimationpt2(m);
	ft_clean(m);
	m->i = inc;
	m->r = rot;
	ft_all(m);
}
