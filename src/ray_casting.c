/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:51:52 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/25 18:10:00 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

int	perform_ray(t_game *game, int side)
{
	while (1)
	{
		if (game->ray->side_distx < game->ray->side_disty)
		{
			game->ray->side_distx += game->ray->delta_distx;
			game->ray->mapx += game->ray->stepx;
			side = 0;
		}
		else
		{
			game->ray->side_disty += game->ray->delta_disty;
			game->ray->mapy += game->ray->stepy;
			side = 1;
		}
		if (game->map[game->ray->mapy][game->ray->mapx] == '1')
			break ;
	}
	if (side == 0)
		game->ray->wall_dist = game->ray->side_distx - game->ray->delta_distx;
	else
		game->ray->wall_dist = game->ray->side_disty - game->ray->delta_disty;
	game->draw->line_h = (int)SCREEN_HEIGHT / game->ray->wall_dist;
	return (side);
}

void	calculate_pixel(t_game *game, int side)
{
	if (side == 0)
		game->draw->wall_x = game->player->pos_y
			+ game->ray->wall_dist * game->ray->ray_diry;
	else
		game->draw->wall_x = game->player->pos_x
			+ game->ray->wall_dist * game->ray->ray_dirx;
	game->draw->wall_x -= (int)game->draw->wall_x;
	game->draw->draw_s = -game->draw->line_h / 2 + SCREEN_HEIGHT / 2;
	game->draw->draw_e = game->draw->line_h / 2 + SCREEN_HEIGHT / 2;
	if (game->draw->draw_s < 0)
		game->draw->draw_s = 0;
	if (game->draw->draw_e > SCREEN_HEIGHT || game->draw->draw_e < 0)
		game->draw->draw_e = SCREEN_HEIGHT;
	game->draw->tex_x = game->draw->tex_w
		- (int)(game->draw->wall_x * game->draw->tex_w);
	game->draw->step = (double)game->draw->tex_h / game->draw->line_h;
	game->draw->tex_pos = (game->draw->draw_s
			- (SCREEN_HEIGHT / 2) + game->draw->line_h / 2) * game->draw->step;
}

static void	draw_vertical(t_game *game, int x, int side, int y)
{
	while (++y < SCREEN_HEIGHT)
	{
		game->draw->tex_y = (int)game->draw->tex_pos;
		if (y < game->draw->draw_s)
			game->draw->color = game->tex->ceilingc;
		else if (y > game->draw->draw_e)
			game->draw->color = game->tex->floorc;
		else
		{
			if (side == 0 && game->ray->ray_dirx < 0)
				game->draw->color = game->tex->we->addr[game->draw->tex_h
					* game->draw->tex_y + game->draw->tex_x];
			else if (side == 0 && game->ray->ray_dirx >= 0)
				game->draw->color = game->tex->ea->addr[game->draw->tex_h
					* game->draw->tex_y + game->draw->tex_x];
			if (side == 1 && game->ray->ray_diry < 0)
				game->draw->color = game->tex->no->addr[game->draw->tex_h
					* game->draw->tex_y + game->draw->tex_x];
			else if (side == 1 && game->ray->ray_diry >= 0)
				game->draw->color = game->tex->so->addr[game->draw->tex_h
					* game->draw->tex_y + game->draw->tex_x];
			game->draw->tex_pos += game->draw->step;
		}
		game->image->addr[y * SCREEN_WIDTH + x] = game->draw->color;
	}
}

int	ray_casting(t_game *game)
{
	int	x;
	int	side;

	x = -1;
	movements(game);
	while (++x < SCREEN_WIDTH)
	{
		calculate_ray(game, x);
		calculate_step(game);
		side = perform_ray(game, 0);
		calculate_pixel(game, side);
		draw_vertical(game, x, side, -1);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->image->img, 0, 0);
	return (0);
}
