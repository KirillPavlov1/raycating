/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:42:41 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:57:33 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	solid(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL
		|| !ft_strchr("01234NEWS", map[y][x]))
		return (0);
	if (map[y][x] == '1' || map[y][x] == '3' || map[y][x] == '4')
		return (1);
	if (map[y][x] == '0')
		map[y][x] = '3';
	if (map[y][x] == '2')
		map[y][x] = '4';
	return (solid(map, x - 1, y)
		&& solid(map, x, y + 1)
		&& solid(map, x, y - 1)
		&& solid(map, x + 1, y));
}

static void	clean_map(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '3')
				map[y][x] = '0';
			if (map[y][x] == '4')
				map[y][x] = '2';
		}
	}
}

int			ft_validator(t_mlx *lib)
{
	int	x;
	int	y;
	int	res;

	x = -1;
	y = -1;
	res = 1;
	while (lib->map[++y] && res)
	{
		x = -1;
		while (lib->map[y][++x] && res)
		{
			if (ft_strchr("NEWS02", lib->map[y][x]))
				res = solid(lib->map, x, y);
		}
	}
	if (!res)
		ft_error("not a valid map");
	clean_map(lib->map);
	return (1);
}
