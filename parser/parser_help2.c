/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-help2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:43:14 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:43:16 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parser2(t_mlx *lib, char **str)
{
	char	**new;
	char	*join;

	join = join_strs(str);
	if (!join)
		ft_error("malloc error");
	new = ft_split(join, ',');
	if (!new)
		ft_error("malloc error");
	if (count_2dem(new) != 3)
		ft_error("args of C are not 3");
	if (!(check_onsym(new)))
		ft_error("sym after digit");
	if (!(check_255(new)))
		ft_error("args of C are not in good range");
	lib->s_config.s_c.r = ft_atoi(new[0]);
	lib->s_config.s_c.g = ft_atoi(new[1]);
	lib->s_config.s_c.b = ft_atoi(new[2]);
	free(join);
	free2dem(new);
	return (1);
}

int	parser_continue5(char **str, t_mlx *lib)
{
	if (!(ft_strncmp(str[0], "C", 2)))
	{
		if (lib->s_config.s_c.r != -1)
			ft_error("some C");
		if (!(parser2(lib, str)))
			ft_error("malloc error");
		return (2);
	}
	return (1);
}
