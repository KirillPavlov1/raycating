/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:40:39 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:49:07 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		cross_parallel(t_mlx *lib, int x, int y)
{
	if (lib->s_ray_dir.y == 0 && !y)
	{
		lib->s_cross_x.x = -1000;
		lib->s_cross_x.y = -1000;
	}
	if (lib->s_ray_dir.x == 0 && !x)
	{
		lib->s_cross_y.x = -1000;
		lib->s_cross_y.y = -1000;
	}
	return (1);
}

double	count_n(t_mlx *lib, int x, int y)
{
	double	q;
	double	sn;
	double	fn;

	q = -(lib->s_ray_dir.x) / lib->s_ray_dir.y;
	fn = (double)((double)(lib->s_player.x - (double)lib->s_net.x)
			+ q * (double)(lib->s_player.y - (double)lib->s_net.y));
	sn = x + q * y;
	return (fn / sn);
}

int		cross(t_mlx *lib, int x, int y)
{
	double	n;

	if ((lib->s_ray_dir.y == 0 && !y) || (lib->s_ray_dir.x == 0 && !x))
		return (cross_parallel(lib, x, y));
	if (lib->s_ray_dir.y)
		n = count_n(lib, x, y);
	else
		n = lib->s_player.y - lib->s_net.y;
	if (x == 0)
	{
		lib->s_cross_y.x = lib->s_net.x + (double)n * x;
		lib->s_cross_y.y = lib->s_net.y + (double)n * y;
	}
	else
	{
		lib->s_cross_x.x = lib->s_net.x + n * x;
		lib->s_cross_x.y = lib->s_net.y + n * y;
	}
	return (1);
}

int		choose_dot(t_mlx *lib)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = lib->s_cross_x.x;
	y1 = lib->s_cross_x.y;
	x2 = lib->s_cross_y.x;
	y2 = lib->s_cross_y.y;
	if (sqrt(pow(lib->s_player.x - x1, 2) + pow(lib->s_player.y - y1, 2))
		< sqrt(pow(lib->s_player.x - x2, 2) + pow(lib->s_player.y - y2, 2)))
	{
		lib->s_dot.x = x1;
		lib->s_dot.y = y1;
	}
	else
	{
		lib->s_dot.x = x2;
		lib->s_dot.y = y2;
	}
	return (1);
}

void	init_net(t_mlx *lib)
{
	if (lib->s_ray_dir.x >= 0 && lib->s_ray_dir.y >= 0)
	{
		lib->s_net.x = (int)lib->s_dot.x + 1;
		lib->s_net.y = (int)lib->s_dot.y + 1;
	}
	else if (lib->s_ray_dir.x >= 0 && lib->s_ray_dir.y <= 0)
	{
		lib->s_net.x = (int)lib->s_dot.x + 1;
		lib->s_net.y = (int)lib->s_dot.y;
	}
	else if (lib->s_ray_dir.y >= 0)
	{
		lib->s_net.y = (int)lib->s_dot.y + 1;
		lib->s_net.x = (int)lib->s_dot.x;
	}
	else
	{
		lib->s_net.y = (int)lib->s_dot.y;
		lib->s_net.x = (int)lib->s_dot.x;
	}
}
