/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:41:00 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:55:21 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	check_cross(t_mlx *lib, int x)
{
	cross_sprite(lib, x);
	dis_sprites(lib);
	sort_sprites(lib);
	if (lib->map[(int)lib->s_dot.y][(int)lib->s_dot.x] == '1')
		return (0);
	if (lib->map[(int)lib->s_dot.y - 1][(int)lib->s_dot.x] == '1')
	{
		if (lib->s_dot.y - (int)lib->s_dot.y == 0
			&& lib->s_dot.x - (int)lib->s_dot.x != 0)
			return (0);
	}
	if (lib->map[(int)lib->s_dot.y][(int)lib->s_dot.x - 1] == '1')
	{
		if (lib->s_dot.y - (int)lib->s_dot.y != 0
			&& lib->s_dot.x - (int)lib->s_dot.x == 0)
			return (0);
	}
	return (1);
}

static void	count_length(t_mlx *lib, int x)
{
	lib->s_dot.x = (int)lib->s_player.x;
	lib->s_dot.y = (int)lib->s_player.y;
	lib->s_cross_y.x = lib->s_player.x;
	lib->s_cross_y.y = lib->s_player.y;
	lib->s_cross_x.x = lib->s_player.x;
	lib->s_cross_x.y = lib->s_player.y;
	init_net(lib);
	cross(lib, 0, 1);
	cross(lib, 1, 0);
	choose_dot(lib);
	while (check_cross(lib, x))
	{
		cross(lib, 0, 1);
		cross(lib, 1, 0);
		choose_dot(lib);
		init_net2(lib);
	}
}

static void	draw_lines(t_mlx *lib, int x, int start, int end)
{
	int	y;
	int	color;

	y = -1;
	while (++y < lib->s_config.res_y)
	{
		if (y <= start)
			my_mlx_pixel_put2(lib, x, y, lib->color_c);
		else if (y > start && y < end)
		{
			color = color_set(lib, x, y, start);
			my_mlx_pixel_put2(lib, x, y, color);
		}
		else if (y >= end)
			my_mlx_pixel_put2(lib, x, y, lib->color_f);
	}
}

static void	count_lineheight(t_mlx *lib, int x)
{
	double	length;

	if (fabs(lib->s_ray_dir.y) < 0.0001)
		length = fabs(lib->s_dot.x - lib->s_player.x);
	else
		length = fabs(lib->s_dot.y - lib->s_player.y) / fabs(lib->s_ray_dir.y);
	lib->z[x] = length;
	if (length > 0.001)
		lib->lineheight = (int)(lib->s_config.res_y / length);
	else
		lib->lineheight = (lib->s_config.res_y);
}

void		draw_3d(t_mlx *lib)
{
	int		x;
	double	camx;
	int		start;
	int		end;

	make_unvisible(lib);
	x = 0;
	while (x < lib->s_config.res_x)
	{
		camx = (double)(2 * x / (double)lib->s_config.res_x) - 1;
		lib->s_ray_dir.x = lib->s_dir.x + lib->s_plane.x * camx;
		lib->s_ray_dir.y = lib->s_dir.y + lib->s_plane.y * camx;
		count_length(lib, x);
		count_lineheight(lib, x);
		start = -lib->lineheight / 2 + lib->s_config.res_y / 2;
		end = lib->lineheight / 2 + lib->s_config.res_y / 2;
		nswe(lib);
		draw_lines(lib, x, start, end);
		x++;
	}
	draw_sprite(lib);
}
