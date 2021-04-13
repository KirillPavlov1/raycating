/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:43:06 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:58:38 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_255(char **new)
{
	int	i;

	i = -1;
	while (new[++i])
	{
		if (ft_atoi(new[i]) > 255 || ft_atoi(new[i]) < 0)
			return (0);
	}
	return (1);
}

int		count_2dem(char **mas)
{
	int	i;

	i = -1;
	while (mas[++i] != NULL)
		;
	return (i);
}

char	*join_strs(char **str)
{
	int		i;
	char	*s;
	char	*new;

	i = 0;
	new = ft_strdup("");
	while (str[++i])
	{
		s = new;
		new = ft_strjoin(new, str[i]);
		free(s);
	}
	return (new);
}

int		check_onsym(char **new)
{
	int	i;
	int	j;

	i = -1;
	while (new[++i])
	{
		j = -1;
		while (new[i][++j])
		{
			if (new[i][j] < '0' || new[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

int		parser3(t_mlx *lib, char **str)
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
		ft_error("args of F are not 3");
	if (!(check_onsym(new)))
		ft_error("sym after digit");
	if (!(check_255(new)))
		ft_error("args of F are not in good range");
	lib->s_config.s_f.r = ft_atoi(new[0]);
	lib->s_config.s_f.g = ft_atoi(new[1]);
	lib->s_config.s_f.b = ft_atoi(new[2]);
	free(join);
	free2dem(new);
	return (1);
}
