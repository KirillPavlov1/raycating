/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sides.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:45:44 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:45:46 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	right_side(t_mlx *lib)
{
	double	x;
	double	y;

	y = lib->s_player.y + lib->s_plane.y / 3;
	x = lib->s_player.x + lib->s_plane.x / 3;
	if (lib->map[(int)y][(int)x] != '0')
		return (0);
	return (1);
}

int	left_side(t_mlx *lib)
{
	double	x;
	double	y;

	y = lib->s_player.y - lib->s_plane.y / 3;
	x = lib->s_player.x - lib->s_plane.x / 3;
	if (lib->map[(int)y][(int)x] != '0')
		return (0);
	return (1);
}

int	up_side(t_mlx *lib)
{
	double	x;
	double	y;

	y = lib->s_player.y + lib->s_dir.y / 3;
	x = lib->s_player.x + lib->s_dir.x / 3;
	if (lib->map[(int)y][(int)x] != '0')
		return (0);
	return (1);
}

int	down_side(t_mlx *lib)
{
	double	x;
	double	y;

	y = lib->s_player.y - lib->s_dir.y / 3;
	x = lib->s_player.x - lib->s_dir.x / 3;
	if (lib->map[(int)y][(int)x] != '0')
		return (0);
	return (1);
}
