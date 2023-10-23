/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:50 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/22 16:00:23 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	err_cf(t_game *game)
{
	free_all(game);
	ft_exit("Error: floor and ceil value must be 0 and 255 range");
}

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

void	free_all(t_game *game)
{
	if (game->map)
		free_double(game->map);
	if (game->map_data.floor)
		free(game->map_data.floor);
	if (game->map_data.ceil)
		free(game->map_data.ceil);
	if (game->map_data.north)
		free(game->map_data.north);
	if (game->map_data.south)
		free(game->map_data.south);
	if (game->map_data.east)
		free(game->map_data.east);
	if (game->map_data.west)
		free(game->map_data.east);
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
