/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:00:42 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/09 04:42:59 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_tile(t_game *game)
{
    char	*moves_str;
    char	*display_str;

    game->moves += 1;
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
        TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
        game->tiles.wall, 0, 0);
    moves_str = ft_itoa(game->moves);
    display_str = ft_strjoin("MOVES: [", moves_str);
    free(moves_str);
    moves_str = ft_strjoin(display_str, "]");
    free(display_str);
    mlx_string_put(game->mlx_ptr, game->win_ptr, 30, 32, 0x000000, moves_str);
    mlx_string_put(game->mlx_ptr, game->win_ptr, 26, 32, 0x000000, moves_str);
    mlx_string_put(game->mlx_ptr, game->win_ptr, 28, 34, 0x000000, moves_str);
    mlx_string_put(game->mlx_ptr, game->win_ptr, 28, 30, 0x000000, moves_str);
    mlx_string_put(game->mlx_ptr, game->win_ptr, 28, 32, 0x00FFFF, moves_str);
    free(moves_str);
}

/* Check if player has collided with any enemy */
int	check_enemy_collision(t_game *game)
{
    int	i;

    i = 0;
    while (i < game->map.enemy)
    {
        if (game->map.player_pos.x == game->map.enemy_pos[i].x
            && game->map.player_pos.y == game->map.enemy_pos[i].y)
        {
            ft_printf("GAME OVER! Caught by enemy.\n");
            return (quit_game(game));
        }
        i++;
    }
    return (0);
}

/* Move enemies in random directions */
void	move_enemy(t_game *game)
{
    int		i;
    int		direction;
    t_point	new_pos;

    i = 0;
    while (i < game->map.enemy)
    {
        direction = rand() % 4; // 0: up, 1: right, 2: down, 3: left
        new_pos = game->map.enemy_pos[i];
        
        if (direction == 0)
            new_pos.y -= 1;
        else if (direction == 1)
            new_pos.x += 1;
        else if (direction == 2)
            new_pos.y += 1;
        else
            new_pos.x -= 1;
            
        if (game->map.map[new_pos.y][new_pos.x] != WALL
            && game->map.map[new_pos.y][new_pos.x] != EXIT
            && game->map.map[new_pos.y][new_pos.x] != COLLECTIBLE)
        {
            // Clear old position
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                game->tiles.floor, 
                TILE_SIZE * game->map.enemy_pos[i].x,
                TILE_SIZE * game->map.enemy_pos[i].y);
                
            // Update position
            game->map.enemy_pos[i] = new_pos;
            
            // Draw enemy at new position
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                game->tiles.enemy,
                TILE_SIZE * new_pos.x, TILE_SIZE * new_pos.y);
        }
        i++;
    }
    check_enemy_collision(game);
}

static void	which_tile(t_game *game)
{
    if (game->map.map[game->map.player_pos.y]
        [game->map.player_pos.x] == COLLECTIBLE)
    {
        game->map.map[game->map.player_pos.y]
        [game->map.player_pos.x] = OPEN_SPACE;
        game->map.collectibles -= 1;
        return ;
    }
    if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == EXIT
        && game->map.collectibles == 0)
    {
        ft_printf(WIN_MSG);
        quit_game(game);
    }
}

/* Overloads the player tile that is left behind when the player moves */
static void	update_left_behind_tile(t_game *game)
{
    if (game->map.map[game->map.player_pos.y]
        [game->map.player_pos.x] == EXIT)
    {
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->tiles.exit,
            TILE_SIZE * game->map.player_pos.x,
            TILE_SIZE * game->map.player_pos.y);
    }
    else
        mlx_put_image_to_window(
            game->mlx_ptr, game->win_ptr, game->tiles.floor,
            TILE_SIZE * game->map.player_pos.x,
            TILE_SIZE * game->map.player_pos.y);
}

void	update_player_pos(t_game *game, bool horizontal, int length)
{
    if (horizontal)
    {
        if (game->map.map[game->map.player_pos.y]
            [game->map.player_pos.x + length] == WALL ||
            (game->map.map[game->map.player_pos.y]
            [game->map.player_pos.x + length] == EXIT && game->map.collectibles > 0))
            return ;
        update_left_behind_tile(game);
        game->map.player_pos.x += length;
    }
    else
    {
        if (game->map.map[game->map.player_pos.y + length]
            [game->map.player_pos.x] == WALL ||
            (game->map.map[game->map.player_pos.y + length]
            [game->map.player_pos.x] == EXIT && game->map.collectibles > 0))
            return ;
        update_left_behind_tile(game);
        game->map.player_pos.y += length;
    }
    which_tile(game);
    put_player_tile(game);
    check_enemy_collision(game);
    move_enemy(game);  // Move enemies after player moves
}
