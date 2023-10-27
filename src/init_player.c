/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:57:45 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/27 16:31:59 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdlib.h>

void	check_pos(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
				++c;
			++j;
		}
		j = 0;
		++i;
	}
	if (c > 1)
	{
		free_all(game);
		ft_exit("Error: more than one player");
	}
}

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	game->player->pos_x = 0.5;
	game->player->pos_y = 0.5;
	game->player->dir_x = 0;
	game->player->dir_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0;
	game->player->rot_speed = 0.03;
	game->player->speed = 0.05;
	find_pos(game->player, game);
	check_pos(game);
}

void	find_pos(t_player *player, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				player->pos_x += j;
				player->pos_y += i;
				player->way = game->map[i][j];
				break ;
			}
			++j;
		}
		j = 0;
		++i;
	}
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}
