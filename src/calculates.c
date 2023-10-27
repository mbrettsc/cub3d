/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:04:36 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/25 18:07:15 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	calculate_ray(t_game *game, int x)
{
	game->ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	game->ray->ray_dirx = game->player->dir_x
		+ game->player->plane_x * game->ray->camera_x;
	game->ray->ray_diry = game->player->dir_y
		+ game->player->plane_y * game->ray->camera_x;
	game->ray->mapx = (int)game->player->pos_x;
	game->ray->mapy = (int)game->player->pos_y;
	if (game->ray->ray_dirx == 0)
		game->ray->delta_distx = 1e30;
	else
		game->ray->delta_distx = fabs(1 / game->ray->ray_dirx);
	if (game->ray->ray_diry == 0)
		game->ray->delta_disty = 1e30;
	else
		game->ray->delta_disty = fabs(1 / game->ray->ray_diry);
}

void	calculate_step(t_game *game)
{
	if (game->ray->ray_dirx < 0)
	{
		game->ray->stepx = -1;
		game->ray->side_distx = (game->player->pos_x - game->ray->mapx)
			* game->ray->delta_distx;
	}
	else
	{
		game->ray->stepx = 1;
		game->ray->side_distx = (game->ray->mapx + 1.0 - game->player->pos_x)
			* game->ray->delta_distx;
	}
	if (game->ray->ray_diry < 0)
	{
		game->ray->stepy = -1;
		game->ray->side_disty = (game->player->pos_y - game->ray->mapy)
			* game->ray->delta_disty;
	}
	else
	{
		game->ray->stepy = 1;
		game->ray->side_disty = (game->ray->mapy + 1.0 - game->player->pos_y)
			* game->ray->delta_disty;
	}
}
