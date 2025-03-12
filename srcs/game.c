/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:00:42 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/11 23:40:51 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player_and_counter(t_game *game)
{
	char	*moves_str;
	char	*display;

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->tiles.wall, 0, 0);
	moves_str = ft_itoa(game->moves);
	display = ft_strjoin("MOVES: ", moves_str);
	free(moves_str);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 17, 25, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 13, 25, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 27, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 23, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 17, 27, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 13, 27, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 17, 23, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 13, 23, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 16, 25, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 14, 25, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 26, 0x000000, display);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 25, 0xFFFF00, display);
	free(display);
}

static void	process_tile_interaction(t_game *game)
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

static void	render_previous_position(t_game *game)
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

void	move_player(t_game *game, bool horizontal, int length)
{
	if (horizontal)
	{
		if (game->map.map[game->map.player_pos.y]
			[game->map.player_pos.x + length] == WALL
			|| (game->map.map[game->map.player_pos.y]
				[game->map.player_pos.x + length] == EXIT
				&&game->map.collectibles > 0))
			return ;
		render_previous_position(game);
		game->map.player_pos.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_pos.y + length]
			[game->map.player_pos.x] == WALL
			|| (game->map.map[game->map.player_pos.y + length]
				[game->map.player_pos.x] == EXIT
				&&game->map.collectibles > 0))
			return ;
		render_previous_position(game);
		game->map.player_pos.y += length;
	}
	game->moves++;
	process_tile_interaction(game);
	render_player_and_counter(game);
}
