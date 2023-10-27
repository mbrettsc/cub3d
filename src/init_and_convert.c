/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:33:07 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/25 17:02:36 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

unsigned int	get_color(int *arr)
{
	unsigned int	ret;

	ret = (arr[0] * 256 * 256)
		+ (arr[1] * 256) + (arr[2]);
	return (ret);
}

void	init_texture(t_game *game)
{
	game->tex = malloc(sizeof(t_texture));
	game->tex->no = malloc(sizeof(t_data));
	game->tex->so = malloc(sizeof(t_data));
	game->tex->we = malloc(sizeof(t_data));
	game->tex->ea = malloc(sizeof(t_data));
}

void	get_address(t_game *game)
{
	int	a;

	game->tex->ea->addr
		= (int *)mlx_get_data_addr(game->tex->ea->img, &a, &a, &a);
	game->tex->we->addr
		= (int *)mlx_get_data_addr(game->tex->we->img, &a, &a, &a);
	game->tex->no->addr
		= (int *)mlx_get_data_addr(game->tex->no->img, &a, &a, &a);
	game->tex->so->addr
		= (int *)mlx_get_data_addr(game->tex->so->img, &a, &a, &a);
}

void	convert_xpm(t_game *game)
{
	int	rand;

	init_texture(game);
	game->tex->floorc = get_color(game->map_data.floor_val);
	game->tex->ceilingc = get_color(game->map_data.ceil_val);
	game->tex->no->img = mlx_xpm_file_to_image(game,
			game->map_data.north, &rand, &rand);
	game->tex->so->img = mlx_xpm_file_to_image(game,
			game->map_data.south, &rand, &rand);
	game->tex->we->img = mlx_xpm_file_to_image(game,
			game->map_data.west, &rand, &rand);
	game->tex->ea->img = mlx_xpm_file_to_image(game,
			game->map_data.east, &rand, &rand);
	get_address(game);
}

void	check_player(t_game *game, char way)
{
	if (way == 'N')
	{
		game->player->dir_y = -1.00;
		game->player->plane_x = 0.66;
	}
	else if (way == 'S')
	{
		game->player->dir_y = 1.00;
		game->player->plane_x = -0.66;
	}
	else if (way == 'E')
	{
		game->player->dir_x = 1.00;
		game->player->plane_y = 0.66;
	}
	else if (way == 'W')
	{
		game->player->dir_x = -1.00;
		game->player->plane_y = -0.66;
	}
}
