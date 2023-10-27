/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:51:28 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/25 18:08:58 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

bool	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E' || c == ' ')
		return (true);
	return (false);
}

void	check_cf(t_game *game)
{
	char	**ceil;
	char	**floor;

	floor = ft_split(game->map_data.floor, ',');
	ceil = ft_split(game->map_data.ceil, ',');
	if (!ceil || !floor)
	{
		free_double(ceil);
		free_double(floor);
		free_all(game);
		ft_exit("Error: invalid floor or ceil value");
	}
	cf_valid(game, floor, ceil, 0);
	free_double(floor);
	free_double(ceil);
}

int	check_pairs(t_game *game)
{
	int	fd_n;
	int	fd_s;
	int	fd_e;
	int	fd_w;

	fd_n = open(game->map_data.north, O_RDONLY);
	fd_s = open(game->map_data.south, O_RDONLY);
	fd_e = open(game->map_data.east, O_RDONLY);
	fd_w = open(game->map_data.west, O_RDONLY);
	if (fd_n == -1 || fd_s == -1 || fd_e == -1 || fd_w == -1)
	{
		free_all(game);
		ft_exit("Error: Texture file cannot found");
	}
	check_cf(game);
	return (close(fd_n), close(fd_s), close(fd_e), close(fd_w), 1);
}

void	check_map_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (!is_valid_char(game->map[i][j]))
			{
				free_all(game);
				ft_exit("Error: invalid character in map");
			}
			++j;
		}
		j = 0;
		++i;
	}
}

int	pair_map(t_game *game, char **regex)
{
	int		i;
	char	**tmp;

	i = 0;
	while (i < 6 && regex[i])
	{
		tmp = ft_split(regex[i], ' ');
		if (!check_and_get(game, tmp))
		{
			free_double(tmp);
			free_double(regex);
			free_all(game);
			ft_exit("Error: invalid map format");
		}
		if (tmp)
			free_double(tmp);
		++i;
	}
	return (i);
}
