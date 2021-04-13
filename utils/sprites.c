/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:45:53 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:01:44 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		dis_sprites(t_mlx *lib)
{
	t_sprite	*start;

	start = lib->item;
	while (start)
	{
		start->dis = (start->x - lib->s_player.x) * (start->x - lib->s_player.x)
			+ (start->y - lib->s_player.y) * (start->y - lib->s_player.y);
		start = start->next;
	}
}

static void	sort_sprites2(t_mlx *lib, t_sprite *new,
	t_sprite *old, t_sprite *copy)
{
	t_sprite	*bef_old;

	if (old->dis < new->dis)
	{
		bef_old = lib->item;
		if (old != lib->item)
		{
			while (bef_old->next != old)
				bef_old = bef_old->next;
		}
		old->next = new->next;
		new->next = old;
		if (old != lib->item)
			bef_old->next = new;
		else
			lib->item = new;
		copy = lib->item;
	}
}

void		sort_sprites(t_mlx *lib)
{
	t_sprite	*copy;
	t_sprite	*new;
	t_sprite	*old;

	copy = lib->item;
	old = copy;
	if (copy)
		copy = copy->next;
	new = copy;
	while (copy)
	{
		sort_sprites2(lib, new, old, copy);
		old = copy;
		copy = copy->next;
		new = copy;
	}
}

int			init_sprites(t_mlx *lib)
{
	int	y;
	int	x;

	lib->item = NULL;
	y = 0;
	while (lib->map[y])
	{
		x = 0;
		while (lib->map[y][x])
		{
			if (lib->map[y][x] == '2')
			{
				sprite_add_back(&lib->item, new_sprite(x + 0.5, y + 0.5));
			}
			x++;
		}
		y++;
	}
	dis_sprites(lib);
	sort_sprites(lib);
	return (1);
}
