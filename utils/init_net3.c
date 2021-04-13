/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_net3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:45:06 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:45:07 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_up_down(t_mlx *lib)
{
	if (lib->s_ray_dir.x == 0 && lib->s_dir.y == -1)
	{
		lib->s_net.y = lib->s_net.y - 1;
		return ;
	}
	if (lib->s_ray_dir.x == 0 && lib->s_dir.y == 1)
	{
		lib->s_net.y = lib->s_net.y + 1;
		return ;
	}
	if (lib->s_ray_dir.x == 1 && lib->s_dir.y == 0)
	{
		lib->s_net.x = lib->s_net.x + 1;
		return ;
	}
	if (lib->s_ray_dir.x == -1 && lib->s_dir.y == 0)
	{
		lib->s_net.x = lib->s_net.x - 1;
		return ;
	}
}
