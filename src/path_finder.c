/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:52:50 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/10 16:12:14 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>

void	free_flood(bool **filled_map)
{
	int	i;

	i = 0;
	while (filled_map[i])
	{
		free(filled_map[i]);
		i++;
	}
	free(filled_map);
}

static bool	floodfill(t_game *game, bool **filled_map, int i, int j)
{
	bool	is_surrounded;

	if (i < 0 || i >= find_map_height(game->map)
		|| j < 0 || j >= ft_strlen(game->map[i]) + 1)
	{
		return (false);
	}
	if (game->map[i][j] == '1' || filled_map[i][j] == true)
		return (true);
	else
		filled_map[i][j] = true;
	is_surrounded = true;
	is_surrounded &= floodfill(game, filled_map, i - 1, j);
	is_surrounded &= floodfill(game, filled_map, i + 1, j);
	is_surrounded &= floodfill(game, filled_map, i, j - 1);
	is_surrounded &= floodfill(game, filled_map, i, j + 1);
	return (is_surrounded);
}

int	check_map_surrounded(t_game *game)
{
	int		x;
	int		y;
	int		i;
	bool	**filled_map;
	bool	is_surrounded;

	x = game->player->pos_x;
	y = game->player->pos_y;
	filled_map = ft_calloc(find_map_height(game->map)
			+ 1, sizeof(bool *));
	i = -1;
	while (++i < find_map_height(game->map))
		filled_map[i] = ft_calloc(ft_strlen(game->map[i] + 1), sizeof(bool));
	is_surrounded = floodfill(game, filled_map, y, x);
	free_flood(filled_map);
	if (!is_surrounded)
	{
		free_all(game);
		ft_exit("Error: map is not surrounded by wall");
	}
	return (1);
}
