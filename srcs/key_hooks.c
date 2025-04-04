/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:00:33 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/11 23:41:19 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	handle_key_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		move_player(game, false, -1);
	else if (key == A || key == LEFT)
		move_player(game, true, -1);
	else if (key == S || key == DOWN)
		move_player(game, false, 1);
	else if (key == D || key == RIGHT)
		move_player(game, true, 1);
	return (EXIT_SUCCESS);
}

void	setup_game_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), handle_key_press, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17),
		quit_game, game);
	mlx_loop(game->mlx_ptr);
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		write_error(game, MLX_INIT_ERR);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map.columns * TILE_SIZE, game->map.rows * TILE_SIZE,
			"so_long");
	if (!game->win_ptr)
		write_error(game, MLX_NEW_WINDOW_ERR);
}
