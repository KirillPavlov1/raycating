/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:45:13 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:05:15 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_values(t_mlx *lib)
{
	lib->s_config.res_x = -1;
	lib->s_config.res_y = -1;
	lib->s_config.north = NULL;
	lib->s_config.south = NULL;
	lib->s_config.west = NULL;
	lib->s_config.east = NULL;
	lib->s_config.sprite = NULL;
	lib->s_config.s_f.r = -1;
	lib->s_config.s_f.g = -1;
	lib->s_config.s_f.b = -1;
	lib->s_config.s_c.r = -1;
	lib->s_config.s_c.g = -1;
	lib->s_config.s_c.b = -1;
	lib->map = NULL;
	lib->map_start = 0;
}

void	check_values(t_mlx *lib, t_list **map)
{
	if (lib->s_config.res_x == -1
		|| lib->s_config.res_y == -1
		|| lib->s_config.north == NULL
		|| lib->s_config.south == NULL
		|| lib->s_config.west == NULL
		|| lib->s_config.east == NULL
		|| lib->s_config.sprite == NULL
		|| lib->s_config.s_f.r == -1
		|| lib->s_config.s_f.g == -1
		|| lib->s_config.s_f.b == -1
		|| lib->s_config.s_c.r == -1
		|| lib->s_config.s_c.g == -1
		|| lib->s_config.s_c.b == -1
		|| *map == NULL)
		ft_error("not enough args");
}

int		main_check(int argc, char **argv)
{
	if ((argc == 2 && check_extension(argv[1], ".cub")))
		return (1);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		return (1);
	return (0);
}
