/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:00:35 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/10 15:33:37 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

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

void	init_mlx(t_game *game)
{
	int	a;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "kirwe3d");
	game->image = malloc(sizeof(t_data));
	game->image->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->image->addr = (int *)mlx_get_data_addr(game->image->img, &a, &a, &a);
}

void	init_map_data(t_game *game)
{
	game->map_data.ceil = NULL;
	game->map_data.floor = NULL;
	game->map_data.north = NULL;
	game->map_data.south = NULL;
	game->map_data.west = NULL;
	game->map_data.east = NULL;
}

void	init_ray(t_game *game)
{
	game->ray = malloc(sizeof(t_ray));
	game->ray->camera_x = 0;
	game->ray->delta_distx = 0;
	game->ray->delta_disty = 0;
	game->ray->mapx = 0;
	game->ray->mapy = 0;
	game->ray->ray_dirx = 0;
	game->ray->ray_diry = 0;
	game->ray->side_distx = 0;
	game->ray->side_disty = 0;
	game->ray->wall_dist = 0;
	game->ray->stepx = 0;
	game->ray->stepy = 0;
}

void	init_draw(t_game *game)
{
	game->draw = malloc(sizeof(t_draw));
	game->draw->color = 0;
	game->draw->draw_e = 0;
	game->draw->draw_s = 0;
	game->draw->line_h = 0;
	game->draw->step = 0;
	game->draw->tex_pos = 0;
	game->draw->tex_x = 0;
	game->draw->tex_y = 0;
	game->draw->wall_x = 0;
	game->draw->tex_h = 64;
	game->draw->tex_w = 64;
}

void	init_key(t_game *game)
{
	game->key.ak = false;
	game->key.dk = false;
	game->key.wk = false;
	game->key.sk = false;
	game->key.rk = false;
	game->key.lk = false;
}

void	init(t_game *game)
{
	init_mlx(game);
	init_map_data(game);
	init_ray(game);
	init_draw(game);
	init_key(game);
}

int	find_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		++i;
	return (i);
}
