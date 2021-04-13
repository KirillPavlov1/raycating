/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:41:09 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:41:11 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put2(t_mlx *lib, int x, int y, int color)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (x >= lib->s_config.res_x)
		x = lib->s_config.res_x - 1;
	if (y < 0)
		y = 0;
	if (y >= lib->s_config.res_y)
		y = lib->s_config.res_y - 1;
	dst = lib->s_img2.addr + (y * lib->s_img2.len + x * lib->s_img2.bpp / 8);
	*(unsigned int *)dst = color;
}
