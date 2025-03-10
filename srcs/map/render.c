/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:03:18 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/10 14:01:20 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * Validates that all game textures were loaded correctly
 * Exits with an error if any texture failed to load
 *
 * @param game Pointer to the game structure
 */
static void	validate_textures(t_game *game)
{
	if (!game->tiles.wall)
		write_error(game, WALL_XPM_ERR);
	if (!game->tiles.floor)
		write_error(game, FLOOR_XPM_ERR);
	if (!game->tiles.player)
		write_error(game, PLAYER_XPM_ERR);
	if (!game->tiles.collectible)
		write_error(game, COLLECTIBLE_XPM_ERR);
	if (!game->tiles.exit)
		write_error(game, EXIT_XPM_ERR);
}

/**
 * Loads all required XPM textures for game elements
 * Sources images from file paths defined in asset.h
 *
 * @param game Pointer to the game structure
 */
static void	load_textures(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &img_size, &img_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &img_size, &img_size);
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &img_size, &img_size);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &img_size, &img_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &img_size, &img_size);
	validate_textures(game);
}

/**
 * Places tile images into the window based on the map data
 * Renders all map elements except the player
 *
 * @param game Pointer to the game structure
 */
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
	render_player_and_counter(game);
}

/**
 * Loads textures and renders the entire game map
 * Main rendering function called during initialization
 *
 * @param game Pointer to the game structure
 */
void	render_map(t_game *game)
{
	load_textures(game);
	render_tiles(game);
}
