/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_surrounded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:52:50 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/22 16:52:11 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>

int horizontalcheck(char **map, int i, int j, int flag)
{
    while (map[++i])
    {
        flag = 0;
        j = -1;
        while (map[i][++j])
        {
            if (flag == 0 && map[i][j] == '1')
                flag ^= 1;
            if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
                return (0);
            if (flag == 1 && map[i][j] == ' ')
            {
                if (map[i][j - 1] && ft_strchr("0NSEW", map[i][j - 1]))
                    return (0);
                flag ^= 1;
            }
        }
    }
    return (1);
}

int verticalcheck(char **map, int i, int j, int flag)
{
    while (map[0][++j])
    {
        flag = 0;
        i = 0;
        while (map[i] && map[i][j])
        {
            if (flag == 0 && map[i][j] == '1')
                flag ^= 1;
            if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
                return (0);
            if (flag == 1 && map[i][j] == ' ')
            {
                if (map[i - 1] && map[i - 1][j]
                        && ft_strchr("0NSEW", map[i - 1][j]))
                    return (0);
                flag ^= 1;
            }
            if (!map[i + 1] && ft_strchr("NSEW0", map[i][j]))
                return (0);
            i++;
        }
    }
    return (1);
}

int	check_map_surrounded(t_game *game)
{
	
	if (!verticalcheck(game->map, -1, -1, 0))
	{
		ft_exit("Error: map is not surrounded by wall");
	}
	if (!horizontalcheck(game->map, -1, -1, 0))
	{
		ft_exit("Error: map is not surrounded by wall");
	}
	return (1);
}
