/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:03:18 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/09 04:37:39 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_error_on_xpms(t_game *game)
{	
    if (!game->tiles.wall)
        write_error(game, WALL_XPM_ERR);
    if (!game->tiles.floor)
        write_error(game, PLAYER_XPM_ERR);
    if (!game->tiles.player)
        write_error(game, PLAYER_XPM_ERR);
    if (!game->tiles.enemy)
        write_error(game, "Enemy XPM file error");
    if (!game->tiles.collectible)
        write_error(game, COLLECTIBLE_XPM_ERR);
    if (!game->tiles.exit)
        write_error(game, EXIT_XPM_ERR);
}

static void	open_xpm(t_game *game)
{	
    int	img_size;

    img_size = TILE_SIZE;
    game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
            WALL_TILE, &img_size, &img_size);
    game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
            FLOOR_TILE, &img_size, &img_size);
    game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
            PLAYER_TILE, &img_size, &img_size);
    game->tiles.enemy = mlx_xpm_file_to_image(game->mlx_ptr,
            ENEMY_TILE, &img_size, &img_size);
    game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
            COLLECTIBLE_TILE, &img_size, &img_size);
    game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
            EXIT_TILE, &img_size, &img_size);
    check_error_on_xpms(game);
}

void	put_enemy_tile(t_game *game)
{
    int	i;

    i = 0;
    while (i < game->map.enemy)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
            game->tiles.enemy, TILE_SIZE * game->map.enemy_pos[i].x,
            TILE_SIZE * game->map.enemy_pos[i].y);
        i++;
    }
}

void	render_tiles(t_game *game)
{
    int		i;
    int		j;

    i = -1;
    while (++i < game->map.rows)
    {
        j = -1;
        while (++j < game->map.columns)
        {
            if (game->map.map[i][j] == WALL)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                    game->tiles.wall, TILE_SIZE * j, TILE_SIZE * i);
            else if (game->map.map[i][j] == COLLECTIBLE)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                    game->tiles.collectible, TILE_SIZE * j, TILE_SIZE * i);
            else if (game->map.map[i][j] == EXIT)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                    game->tiles.exit, TILE_SIZE * j, TILE_SIZE * i);
            else
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                    game->tiles.floor, TILE_SIZE * j, TILE_SIZE * i);
        }
    }
    put_player_tile(game);
    put_enemy_tile(game);
}

void	render_map(t_game *game)
{
    open_xpm(game);
    render_tiles(game);
}
