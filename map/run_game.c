/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:42:31 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:57:10 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	close_game(t_mlx *lib)
{
	mlx_destroy_window(lib->mlx, lib->mlx_win);
	exit(0);
	return (0);
}

static int	press_button(int keycode, t_mlx *lib)
{
	if (keycode == 123)
		lib->l = 1;
	if (keycode == 124)
		lib->r = 1;
	if (keycode == 13 && up_side(lib))
		lib->w = 1;
	if (keycode == 0 && left_side(lib))
		lib->a = 1;
	if (keycode == 1 && down_side(lib))
		lib->s = 1;
	if (keycode == 2 && right_side(lib))
		lib->d = 1;
	if (keycode == 53)
		close_game(lib);
	return (0);
}

static int	up_button(int keycode, t_mlx *lib)
{
	if (keycode == 123)
		lib->l = 0;
	if (keycode == 124)
		lib->r = 0;
	if (keycode == 13)
		lib->w = 0;
	if (keycode == 0)
		lib->a = 0;
	if (keycode == 1)
		lib->s = 0;
	if (keycode == 2)
		lib->d = 0;
	return (0);
}

static int	display_img(t_mlx *lib)
{
	move_player(lib);
	mlx_destroy_image(lib->mlx, lib->s_img2.img);
	lib->s_img2.img = mlx_new_image(lib->mlx, lib->s_config.res_x,
			lib->s_config.res_y);
	lib->s_img2.addr = mlx_get_data_addr(lib->s_img2.img, &lib->s_img2.bpp,
			&lib->s_img2.len, &lib->s_img2.endian);
	draw_3d(lib);
	if (lib->screen == 1)
		make_screen(lib);
	mlx_put_image_to_window(lib->mlx, lib->mlx_win, lib->s_img2.img, 0, 0);
	return (0);
}

int			run_game(t_mlx *lib)
{
	lib->angle = -M_PI_2;
	mlx_hook(lib->mlx_win, 2, 1L << 0, press_button, lib);
	mlx_hook(lib->mlx_win, 17, 1L << 0, close_game, lib);
	mlx_loop_hook(lib->mlx, display_img, lib);
	mlx_hook(lib->mlx_win, 3, 1L << 1, up_button, lib);
	mlx_loop(lib->mlx);
	return (1);
}
