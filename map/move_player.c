/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:41:55 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:56:46 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	move_player2(t_mlx *lib)
{
	if (lib->w && up_side(lib))
	{
		lib->s_player.y = lib->s_player.y + lib->s_dir.y / 3;
		lib->s_player.x = lib->s_player.x + lib->s_dir.x / 3;
	}
	if (lib->a && left_side(lib))
	{
		lib->s_player.y = lib->s_player.y - lib->s_plane.y / 3;
		lib->s_player.x = lib->s_player.x - lib->s_plane.x / 3;
	}
	if (lib->s && down_side(lib))
	{
		lib->s_player.y = lib->s_player.y - lib->s_dir.y / 3;
		lib->s_player.x = lib->s_player.x - lib->s_dir.x / 3;
	}
	if (lib->d && right_side(lib))
	{
		lib->s_player.y = lib->s_player.y + lib->s_plane.y / 3;
		lib->s_player.x = lib->s_player.x + lib->s_plane.x / 3;
	}
}

static void	move_player1(t_mlx *lib)
{
	double	x;

	if (lib->r)
	{
		lib->angle = lib->angle + M_PI / 60;
		x = lib->s_dir.x;
		lib->s_dir.x = lib->s_dir.x * cos(M_PI / 60)
			- lib->s_dir.y * sin(M_PI / 60);
		lib->s_dir.y = x * sin(M_PI / 60) + lib->s_dir.y * cos(M_PI / 60);
		x = lib->s_plane.x;
		lib->s_plane.x = lib->s_plane.x * cos(M_PI / 60)
			- lib->s_plane.y * sin(M_PI / 60);
		lib->s_plane.y = x * sin(M_PI / 60) + lib->s_plane.y * cos(M_PI / 60);
	}
}

void		move_player(t_mlx *lib)
{
	double	x;

	if (lib->l)
	{
		lib->angle = lib->angle - M_PI / 60;
		x = lib->s_dir.x;
		lib->s_dir.x = lib->s_dir.x * cos(M_PI / 60)
			+ lib->s_dir.y * sin(M_PI / 60);
		lib->s_dir.y = -1 * x * sin(M_PI / 60) + lib->s_dir.y * cos(M_PI / 60);
		x = lib->s_plane.x;
		lib->s_plane.x = lib->s_plane.x * cos(M_PI / 60)
			+ lib->s_plane.y * sin(M_PI / 60);
		lib->s_plane.y = -1 * x * sin(M_PI / 60)
			+ lib->s_plane.y * cos(M_PI / 60);
	}
	move_player1(lib);
	move_player2(lib);
}
