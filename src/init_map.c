/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:08:17 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/11 15:23:49 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

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

unsigned int	get_color(int *arr)
{
	int				i;
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
	game->tex->no->img = mlx_xpm_file_to_image(game, game->map_data.north, &rand, &rand);
	game->tex->so->img = mlx_xpm_file_to_image(game, game->map_data.south, &rand, &rand);
	game->tex->we->img = mlx_xpm_file_to_image(game, game->map_data.west, &rand, &rand);
	game->tex->ea->img = mlx_xpm_file_to_image(game, game->map_data.east, &rand, &rand);
	get_address(game);
}

void	check_player(t_game *game, char way)
{
	if (way == 'N')
	{
		game->player->dir_x = 0.00;
		game->player->dir_y = -1.00;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0;
	}
	else if (way == 'S')
	{
		game->player->dir_x = 0.00;
		game->player->dir_y = 1.00;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0;
	}
	else if (way == 'E')
	{
		game->player->dir_x = 1.00;
		game->player->dir_y = 0.00;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66;
	}
	else if (way == 'W')
	{
		game->player->dir_x = -1.00;
		game->player->dir_y = 0.00;
		game->player->plane_x = 0;
		game->player->plane_y = -0.66;
	}
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
