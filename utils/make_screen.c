/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:45:21 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:03:12 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	init_header(t_mlx *lib, int fd)
{
	int	value;

	write(fd, "BM", 2);
	value = 14 + 40 + lib->s_config.res_x * lib->s_config.res_y
		* lib->s_img2.bpp / 8;
	write(fd, &value, 4);
	value = 0;
	write(fd, &value, 4);
	value = 14 + 40;
	write(fd, &value, 4);
	value = 40;
	write(fd, &value, 4);
	write(fd, &lib->s_config.res_x, 4);
	write(fd, &lib->s_config.res_y, 4);
	value = 1;
	write(fd, &value, 2);
	write(fd, &lib->s_img2.bpp, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
}

void		make_screen(t_mlx *lib)
{
	char	*file;
	int		fd;
	int		y;

	file = "screen.bmp";
	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		ft_error("problems with screen.bmp");
	init_header(lib, fd);
	y = lib->s_config.res_y;
	if (y > 23000 || lib->s_config.res_x > 23000)
		ft_error("too big res for screen");
	while (y-- > 0)
	{
		write(fd, (lib->s_img2.addr + y * lib->s_img2.len),
			(lib->s_config.res_x * lib->s_img2.bpp / 8));
	}
	close(fd);
	exit(0);
}
