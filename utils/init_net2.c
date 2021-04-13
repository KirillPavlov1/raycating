/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_net2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:44:57 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:04:31 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	init_up_left(t_mlx *lib)
{
	double	x;
	double	y;

	x = lib->s_dot.x;
	y = lib->s_dot.y;
	if (lib->s_ray_dir.x < 0 && lib->s_ray_dir.y < 0)
	{
		if ((int)x - x == 0 && (int)y - y == 0 && lib->s_ray_dir.x == 0)
		{
			lib->s_net.y = lib->s_dot.y - 1;
			return ;
		}
		if ((int)x - x == 0)
			lib->s_net.x = lib->s_dot.x - 1;
		else
			lib->s_net.x = (int)lib->s_dot.x;
		if ((int)y - y == 0)
			lib->s_net.y = lib->s_dot.y - 1;
		else
			lib->s_net.y = (int)lib->s_dot.y;
		return ;
	}
}

static void	init_up_right(t_mlx *lib)
{
	double	x;
	double	y;

	x = lib->s_dot.x;
	y = lib->s_dot.y;
	if (lib->s_ray_dir.x > 0 && lib->s_ray_dir.y < 0)
	{
		if ((int)x - x == 0)
			lib->s_net.x = lib->s_dot.x + 1;
		else
			lib->s_net.x = (int)lib->s_dot.x + 1;
		if ((int)y - y == 0)
			lib->s_net.y = lib->s_dot.y - 1;
		else
			lib->s_net.y = (int)lib->s_dot.y;
		return ;
	}
}

static void	init_down_left(t_mlx *lib)
{
	double	x;
	double	y;

	x = lib->s_dot.x;
	y = lib->s_dot.y;
	if (lib->s_ray_dir.x < 0 && lib->s_ray_dir.y > 0)
	{
		if ((int)x - x == 0 && (int)y - y == 0 && lib->s_ray_dir.y == 0)
		{
			lib->s_net.y = lib->s_dot.y + 1;
			return ;
		}
		if ((int)x - x == 0)
			lib->s_net.x = lib->s_dot.x - 1;
		else
			lib->s_net.x = (int)lib->s_dot.x;
		lib->s_net.y = (int)lib->s_dot.y + 1;
		return ;
	}
}

static void	init_down_right(t_mlx *lib)
{
	double	x;
	double	y;

	x = lib->s_dot.x;
	y = lib->s_dot.y;
	if (lib->s_ray_dir.x > 0 && lib->s_ray_dir.y > 0)
	{
		lib->s_net.x = (int)lib->s_dot.x + 1;
		lib->s_net.y = (int)lib->s_dot.y + 1;
		return ;
	}
}

void		init_net2(t_mlx *lib)
{
	init_up_down(lib);
	init_up_left(lib);
	init_up_right(lib);
	init_down_right(lib);
	init_down_left(lib);
}
