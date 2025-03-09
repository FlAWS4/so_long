/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:00:33 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/09 04:44:38 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>  // For srand/rand

int	quit_game(t_game *game)
{
    destroy(game);
    exit(EXIT_SUCCESS);
    return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
    if (key == ESC)
        quit_game(game);
    else if (key == W || key == UP)
        update_player_pos(game, false, -1);
    else if (key == A || key == LEFT)
        update_player_pos(game, true, -1);
    else if (key == S || key == DOWN)
        update_player_pos(game, false, 1);
    else if (key == D || key == RIGHT)
        update_player_pos(game, true, 1);
    return (EXIT_SUCCESS);
}

int	enemy_loop(t_game *game)
{
    // Move enemies on their own every frame
    if (game->map.enemy > 0)
        move_enemy(game);
    return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
    // Initialize random seed for enemy movement
    srand(time(NULL));
    
    mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), on_press, game);
    mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17),
        quit_game, game);
        
    // Add loop hook for continuous enemy movement (optional)
    // Uncomment to have enemies move continuously
    // mlx_loop_hook(game->mlx_ptr, enemy_loop, game);
    
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
