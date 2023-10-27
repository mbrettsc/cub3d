/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:50 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/25 16:24:45 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	free_all_ext(t_game *game)
{
	if (game->tex)
	{
		mlx_destroy_image(game->mlx, game->tex->ea->img);
		mlx_destroy_image(game->mlx, game->tex->so->img);
		mlx_destroy_image(game->mlx, game->tex->we->img);
		mlx_destroy_image(game->mlx, game->tex->no->img);
	}
	if (game->map_data.north)
	{
		free(game->map_data.north);
		free(game->map_data.south);
		free(game->map_data.east);
		free(game->map_data.west);
		if (game->map_data.ceil)
		{
			free(game->map_data.ceil);
			free(game->map_data.floor);
		}
	}
}

void	free_all(t_game *game)
{
	if (game->map)
		free_double(game->map);
	if (game->ray)
		free(game->ray);
	if (game->draw)
		free(game->draw);
	if (game->image)
	{
		mlx_destroy_image(game->mlx, game->image->img);
		free(game->image);
	}
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->player)
		free(game->player);
	free_all_ext(game);
}

char	*ft_straddchar(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	if (!s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (str);
}
