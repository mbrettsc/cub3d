/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:00:35 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/25 18:07:43 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	find_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		++i;
	return (i);
}

int	is_valid1(char *str)
{
	static int	no_flag;
	static int	so_flag;
	static int	we_flag;

	if (!ft_strcmp(str, "NO") && no_flag == 0)
	{
		no_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "SO") && so_flag == 0)
	{
		so_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "WE") && we_flag == 0)
	{
		we_flag = 1;
		return (1);
	}
	return (0);
}

int	is_valid2(char *str)
{
	static int	ea_flag;
	static int	c_flag;
	static int	f_flag;

	if (!ft_strcmp(str, "EA") && ea_flag == 0)
	{
		ea_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "C") && c_flag == 0)
	{
		c_flag = 1;
		return (1);
	}
	if (!ft_strcmp(str, "F") && f_flag == 0)
	{
		f_flag = 1;
		return (1);
	}
	return (0);
}

int	check_and_get(t_game *game, char **regex)
{
	if (is_valid1(regex[0]) || is_valid2(regex[0]))
	{
		if (!ft_strcmp(regex[0], "NO"))
			game->map_data.north = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "SO"))
			game->map_data.south = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "WE"))
			game->map_data.west = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "EA"))
			game->map_data.east = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "C"))
			game->map_data.ceil = ft_strdup(regex[1]);
		else if (!ft_strcmp(regex[0], "F"))
			game->map_data.floor = ft_strdup(regex[1]);
	}
	else
		return (0);
	return (1);
}

void	init(t_game *game)
{
	init_mlx(game);
	init_map_data(game);
	init_ray(game);
	init_draw(game);
	init_key(game);
}
