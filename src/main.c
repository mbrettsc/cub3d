/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:39:52 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/10/10 15:41:31 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	map_check(char *file)
{
	char	*sub;

	sub = ft_substr(file, ft_strlen(file) - 4, ft_strlen(file));
	if (!ft_strcmp(sub, ".cub"))
		return (free(sub), 1);
	return (free(sub), 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		printf("Error: this program accept only 2 arguments\n");
	else if (map_check(av[1]))
	{
		init_map(&game, av[1]);
		mlx_hook(game.window, 2, 1L<<0, key_press, &game);
		mlx_hook(game.window, 3, 1L<<1, key_relase, &game);
		//handle key press and relase
		mlx_hook(game.window, 17, 0, exit_game, &game);
		mlx_do_sync(game.mlx);
		mlx_loop_hook(game.mlx, ray_casting, &game);
		mlx_loop(game.mlx);
	}
	else
		printf("Error: wrong file extension name\n");
	return (0);
}