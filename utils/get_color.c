/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:44:49 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:44:51 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	my_get_color(t_mlx *lib, int x, int y, int i)
{
	char	*dst;

	dst = lib->image[i].addr
		+ (y * lib->image[i].len + x * lib->image[i].bpp / 8);
	return (*(int *)dst);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	color_set(t_mlx *lib, int x, int y, int start)
{
	int	color;

	if (lib->s_player.y < lib->s_dot.y && lib->state == 0)
		color = pour_north(lib, x, y, start);
	if (lib->s_player.y > lib->s_dot.y && lib->state == 0)
		color = pour_south(lib, x, y, start);
	if (lib->s_player.x < lib->s_dot.x && lib->state == 1)
		color = pour_west(lib, x, y, start);
	if (lib->s_player.x > lib->s_dot.x && lib->state == 1)
		color = pour_east(lib, x, y, start);
	return (color);
}
