/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pour.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:45:37 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:01:03 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	pour_north(t_mlx *lib, int x, int y, int start)
{
	int		color;
	double	k;

	k = (double)lib->image[0].y / lib->lineheight;
	x = (int)((1 - (lib->s_dot.x - (int)lib->s_dot.x)) * lib->image[0].x);
	y = (int)(k * (y - start));
	color = my_get_color(lib, x, y, 0);
	return (color);
}

int	pour_south(t_mlx *lib, int x, int y, int start)
{
	int		color;
	double	k;

	k = (double)lib->image[1].y / lib->lineheight;
	x = (int)((lib->s_dot.x - (int)lib->s_dot.x) * lib->image[1].x);
	y = (int)(k * (y - start));
	color = my_get_color(lib, x, y, 1);
	return (color);
}

int	pour_east(t_mlx *lib, int x, int y, int start)
{
	int		color;
	double	k;

	k = (double)lib->image[3].y / lib->lineheight;
	x = (int)((1 - (lib->s_dot.y - (int)lib->s_dot.y)) * lib->image[3].x);
	y = (int)(k * (y - start));
	color = my_get_color(lib, x, y, 3);
	return (color);
}

int	pour_west(t_mlx *lib, int x, int y, int start)
{
	int		color;
	double	k;

	k = (double)lib->image[2].y / lib->lineheight;
	x = (int)((double)(lib->s_dot.y - (int)lib->s_dot.y) * lib->image[2].x);
	y = (int)(k * (y - start));
	color = my_get_color(lib, x, y, 2);
	return (color);
}
