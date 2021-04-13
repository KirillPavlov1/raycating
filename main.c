/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:26:46 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:48:13 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <math.h>

void		check_xpm(t_mlx *lib)
{
	if (open(lib->s_config.north, O_RDONLY) < 0)
		ft_error("not valid way to tex");
	if (open(lib->s_config.east, O_RDONLY) < 0)
		ft_error("not valid way to tex");
	if (open(lib->s_config.west, O_RDONLY) < 0)
		ft_error("not valid way to tex");
	if (open(lib->s_config.south, O_RDONLY) < 0)
		ft_error("not valid way to tex");
	if (open(lib->s_config.sprite, O_RDONLY) < 0)
		ft_error("not valid way to tex");
	create_mlx(lib);
}

void		save_img(t_mlx *lib)
{
	int	i;

	i = -1;
	check_xpm(lib);
	lib->image[0].img = mlx_xpm_file_to_image(lib->mlx,
			lib->s_config.north, &lib->image[0].x, &lib->image[0].y);
	lib->image[1].img = mlx_xpm_file_to_image(lib->mlx,
			lib->s_config.south, &lib->image[1].x, &lib->image[1].y);
	lib->image[2].img = mlx_xpm_file_to_image(lib->mlx,
			lib->s_config.west, &lib->image[2].x, &lib->image[2].y);
	lib->image[3].img = mlx_xpm_file_to_image(lib->mlx,
			lib->s_config.east, &lib->image[3].x, &lib->image[3].y);
	lib->image[4].img = mlx_xpm_file_to_image(lib->mlx,
			lib->s_config.sprite, &lib->image[4].x, &lib->image[4].y);
	while (++i < 5)
	{
		if (!(lib->image[i].img))
			ft_error("not valid way to tex");
	}
	i = -1;
	while (++i < 5)
	{
		lib->image[i].addr = mlx_get_data_addr(lib->image[i].img,
				&lib->image[i].bpp, &lib->image[i].len, &lib->image[i].endian);
	}
}

static int	open_file_gnl(t_mlx *lib, t_list **map, char *str)
{
	int		fd;
	char	*line;

	init_values(lib);
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
		ft_error("map is directory");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Not a valid file");
	while (get_next_line(fd, &line) && (parser(line, lib)))
		free(line);
	if (check_line(line))
		ft_lstadd_back(map, ft_lstnew(line));
	else
		ft_error("wrong data");
	while (get_next_line(fd, &line) && (check_line(line)))
		ft_lstadd_back(map, ft_lstnew(line));
	ft_lstadd_back(map, ft_lstnew(line));
	if (!(check_line(line)))
		ft_error("Not a valid .cub file");
	check_values(lib, map);
	close(fd);
	return (1);
}

static void	main_else(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		ft_error("bad count of argc");
	if (!(check_extension(argv[1], ".cub")))
		ft_error("bad extension");
	if (ft_strncmp(argv[2], "--save", 7))
		ft_error("flag is not --save");
}

int			main(int argc, char **argv)
{
	t_list	*map;
	t_mlx	*lib;

	map = NULL;
	if (main_check(argc, argv))
	{
		lib = ft_newmlx();
		if (argc == 3)
			lib->screen = 1;
		open_file_gnl(lib, &map, argv[1]);
		save_img(lib);
		lib->map = make_map(map, ft_lstsize(map));
		find_player(lib, lib->map);
		ft_validator(lib);
		if (!(lib->pl))
			ft_error("no player");
		init_sprites(lib);
		run_game(lib);
	}
	else
		main_else(argc, argv);
	return (0);
}
