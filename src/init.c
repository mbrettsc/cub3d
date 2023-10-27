/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:30:10 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/23 14:41:26 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	init_mlx(t_game *game)
{
	int	a;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "kirwe3d");
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
