/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:42:58 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:59:09 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int		parser_continue3(char **str, t_mlx *lib)
{
	if (!(ft_strncmp(str[0], "S", 2)))
	{
		if (lib->s_config.sprite != NULL)
			ft_error("some S");
		if (count_2dem(str) != 2)
			ft_error("arg of S is not 1");
		lib->s_config.sprite = ft_substr(str[1], 0, ft_strlen(str[1]));
		if (!lib->s_config.sprite)
			ft_error("malloc error");
		return (2);
	}
	else if (!(ft_strncmp(str[0], "F", 2)))
	{
		if (lib->s_config.s_f.r != -1)
			ft_error("some F");
		if (!(parser3(lib, str)))
			ft_error("malloc error");
		return (2);
	}
	return (1);
}

static int		parser_continue2(char **str, t_mlx *lib)
{
	if (!(ft_strncmp(str[0], "SO", 3)))
	{
		if (lib->s_config.south != NULL)
			ft_error("some SO");
		if (count_2dem(str) != 2)
			ft_error("arg of SO is not 1");
		lib->s_config.south = ft_substr(str[1], 0, ft_strlen(str[1]));
		if (!lib->s_config.south)
			ft_error("malloc error");
		return (2);
	}
	else if (!(ft_strncmp(str[0], "WE", 3)))
	{
		if (lib->s_config.west != NULL)
			ft_error("some WE");
		if (count_2dem(str) != 2)
			ft_error("arg of WE is not 1");
		lib->s_config.west = ft_substr(str[1], 0, ft_strlen(str[1]));
		if (!lib->s_config.west)
			ft_error("malloc error");
		return (2);
	}
	return (1);
}

static int		parser_continue1(char **str, t_mlx *lib)
{
	int	x;
	int	y;

	mlx_get_screen_size(&x, &y);
	if (!ft_strncmp(str[0], "R", 2))
	{
		if (lib->s_config.res_x != -1)
			ft_error("some R");
		if (count_2dem(str) != 3)
			ft_error("args of R are not 2");
		if (!check_onsym(++str))
			ft_error("sym after res");
		lib->s_config.res_x = ft_atoi(str[0]);
		lib->s_config.res_y = ft_atoi(str[1]);
		if (lib->s_config.res_x > x && lib->screen != 1)
			lib->s_config.res_x = x;
		if (lib->s_config.res_y > y && lib->screen != 1)
			lib->s_config.res_y = y;
		if (lib->s_config.res_y == 0 || lib->s_config.res_x == 0)
			ft_error("zero res");
		return (2);
	}
	return (1);
}

static int		parser_continue4(char **str, t_mlx *lib)
{
	if (!(ft_strncmp(str[0], "NO", 3)))
	{
		if (lib->s_config.north != NULL)
			ft_error("some NO");
		if (count_2dem(str) != 2)
			ft_error("arg of NO is not 1");
		lib->s_config.north = ft_substr(str[1], 0, ft_strlen(str[1]));
		if (!lib->s_config.north)
			ft_error("malloc error");
		return (2);
	}
	else if (!(ft_strncmp(str[0], "EA", 3)))
	{
		if (lib->s_config.east != NULL)
			ft_error("some EA");
		if (count_2dem(str) != 2)
			ft_error("arg of EA is not 1");
		lib->s_config.east = ft_substr(str[1], 0, ft_strlen(str[1]));
		if (!lib->s_config.east)
			ft_error("malloc error");
		return (2);
	}
	return (1);
}

unsigned int	parser(char *line, t_mlx *lib)
{
	char	**str;

	str = ft_split(line, ' ');
	if (!str)
		ft_error("malloc error");
	if (lib->map_start && !(check_line(line)))
		ft_error("spaces in config");
	lib->map_start = only_spaces(line);
	if (*str == NULL)
	{
		free2dem(str);
		return (1);
	}
	if (parser_continue1(str, lib) == 1
		&& parser_continue2(str, lib) == 1
		&& parser_continue3(str, lib) == 1
		&& parser_continue4(str, lib) == 1
		&& parser_continue5(str, lib) == 1)
	{
		free2dem(str);
		return (0);
	}
	free2dem(str);
	return (1);
}
