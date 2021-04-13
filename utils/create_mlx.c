/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:43:55 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:43:57 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../libmlx/mlx.h"

t_mlx	*create_mlx(t_mlx *lib)
{
	lib->mlx = mlx_init();
	lib->mlx_win = mlx_new_window(lib->mlx, lib->s_config.res_x,
			lib->s_config.res_y, "map");
	lib->s_img1.img = mlx_new_image(lib->mlx,
			lib->s_config.res_x, lib->s_config.res_y);
	lib->s_img1.addr = mlx_get_data_addr(lib->s_img1.img,
			&lib->s_img1.bpp, &lib->s_img1.len, &lib->s_img1.endian);
	lib->s_img2.img = mlx_new_image(lib->mlx,
			lib->s_config.res_x, lib->s_config.res_y);
	lib->s_img2.addr = mlx_get_data_addr(lib->s_img2.img,
			&lib->s_img2.bpp, &lib->s_img2.len, &lib->s_img2.endian);
	lib->color_c = create_rgb(lib->s_config.s_c.r,
			lib->s_config.s_c.g, lib->s_config.s_c.b);
	lib->color_f = create_rgb(lib->s_config.s_f.r,
			lib->s_config.s_f.g, lib->s_config.s_f.b);
	lib->w = 0;
	lib->a = 0;
	lib->s = 0;
	lib->d = 0;
	lib->l = 0;
	lib->r = 0;
	lib->pl = 0;
	lib->z = (double *)malloc(sizeof(double) * lib->s_config.res_x);
	lib->map_start = 0;
	return (lib);
}
