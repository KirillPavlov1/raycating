/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:41:39 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:56:16 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	xy(t_sprite *tmp, t_mlx *lib)
{
	double	indet;

	lib->s_ds.spritex = tmp->x - lib->s_player.x;
	lib->s_ds.spritey = tmp->y - lib->s_player.y;
	indet = 1.0 / (lib->s_plane.x * lib->s_dir.y
			- lib->s_plane.y * lib->s_dir.x);
	lib->s_ds.transx = indet * (lib->s_dir.y
			* lib->s_ds.spritex - lib->s_dir.x * lib->s_ds.spritey);
	lib->s_ds.transy = indet * (-1.0 * lib->s_plane.y
			* lib->s_ds.spritex + lib->s_plane.x * lib->s_ds.spritey);
	lib->s_ds.screenx = (int)((lib->s_config.res_x / 2)
			* (1 + lib->s_ds.transx / lib->s_ds.transy));
	if (lib->s_ds.transy > 0.001)
		lib->s_ds.w = abs((int)(lib->s_config.res_y / lib->s_ds.transy));
	else
		lib->s_ds.w = lib->s_config.res_y;
	lib->s_ds.endy = lib->s_config.res_y / 2 + lib->s_ds.w / 2;
	lib->s_ds.startx = -lib->s_ds.w / 2 + lib->s_ds.screenx - 1;
	lib->s_ds.endx = lib->s_ds.screenx + lib->s_ds.w / 2;
}

static void	xy2(t_mlx *lib)
{
	int	color;

	while (lib->s_ds.starty < lib->s_ds.endy
		&& lib->s_ds.starty < lib->s_config.res_y
		&& lib->s_ds.startx > -1 && lib->s_ds.transy < lib->z[lib->s_ds.startx])
	{
		lib->s_ds.texy = (int)(((double)(lib->s_ds.w - (lib->s_ds.endy
							- lib->s_ds.starty)) / (double)lib->s_ds.w)
				* (double)lib->image[4].y);
		color = my_get_color(lib, lib->s_ds.texx, lib->s_ds.texy, 4);
		if (color)
			my_mlx_pixel_put2(lib, lib->s_ds.startx, lib->s_ds.starty, color);
		lib->s_ds.starty++;
	}
}

void		draw_sprite(t_mlx *lib)
{
	int			y;
	t_sprite	*tmp;

	tmp = lib->item;
	while (tmp)
	{
		if (tmp->visible)
		{
			xy(tmp, lib);
			y = lib->s_config.res_y / 2 - lib->s_ds.w / 2;
			while (++lib->s_ds.startx < lib->s_ds.endx
				&& lib->s_ds.startx < (int)lib->s_config.res_x)
			{
				lib->s_ds.texx = (int)((double)(lib->s_ds.w - (lib->s_ds.screenx
								+ lib->s_ds.w / 2 - lib->s_ds.startx))
						/ (double)lib->s_ds.w * (double)lib->image[4].x);
				if (y < 0)
					lib->s_ds.starty = 0;
				else
					lib->s_ds.starty = y;
				xy2(lib);
			}
		}
		tmp = tmp->next;
	}
}
