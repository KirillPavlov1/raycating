/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:44:19 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:03:38 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	init_player2(t_mlx *lib, char c)
{
	if (c == 'E')
	{
		lib->s_dir.x = 1;
		lib->s_dir.y = 0;
		lib->s_plane.x = 0;
		lib->s_plane.y = 0.66;
	}
	if (c == 'S')
	{
		lib->s_dir.x = 0;
		lib->s_dir.y = 1;
		lib->s_plane.x = -0.66;
		lib->s_plane.y = 0;
	}
	if (c == 'W')
	{
		lib->s_dir.x = -1;
		lib->s_dir.y = 0;
		lib->s_plane.x = 0;
		lib->s_plane.y = -0.66;
	}
}

static void	init_player(t_mlx *lib, int x, int y, char c)
{
	lib->map[y][x] = '0';
	lib->s_player.x = x + 0.5;
	lib->s_player.y = y + 0.5;
	if (lib->pl != 0)
	{
		ft_error("too many players");
	}
	lib->pl++;
	if (c == 'N')
	{
		lib->s_dir.x = 0;
		lib->s_dir.y = -1;
		lib->s_plane.x = 0.66;
		lib->s_plane.y = 0;
	}
	init_player2(lib, c);
}

void		find_player(t_mlx *lib, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'W' || map[y][x] == 'E')
				init_player(lib, x, y, map[y][x]);
			x++;
		}
		y++;
	}
}
