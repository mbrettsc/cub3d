/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:08:17 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/22 15:46:57 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	parse_map(t_game *game, char *map)
{
	int		i;
	int		j;
	int		len;
	char	**regex;

	len = 0;
	regex = ft_split(map, '\n');
	i = pair_map(game, regex);
	j = i;
	while (regex[j])
	{
		++len;
		++j;
	}
	game->map = malloc(sizeof(char *) * len + 1);
	j = 0;
	while (regex[i])
	{
		game->map[j] = ft_strdup(regex[i]);
		++i;
		++j;
	}
	game->map[j] = NULL;
	free_double(regex);
}

void	check_map(t_game *game)
{
	if (!check_pairs(game))
	{
		ft_exit("Error: invalid sprite");
	}
	init_player(game);
	check_map_surrounded(game);
	check_map_valid(game);
}

char	*read_map(char *file)
{
	int		fd;
	int		status;
	int		i;
	char	map[2];
	char	*ret;

	i = 0;
	status = 1;
	ret = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(printf("Incorrect Map\n"));
	while (status != 0)
	{
		status = read(fd, map, 1);
		map[1] = '\0';
		if (i == 0)
			ret = ft_strdup(map);
		else
			ret = ft_straddchar(ret, map);
		++i;
	}
	close(fd);
	return (ret);
}

void	init_map(t_game *game, char *file)
{
	char	*map;

	map = read_map(file);
	init(game);
	parse_map(game, map);
	check_map(game);
	convert_xpm(game);
	check_player(game, game->player->way);
	free(map);
}
