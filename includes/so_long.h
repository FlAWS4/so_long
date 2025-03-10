/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:48:34 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/10 10:21:47 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "asset.h"
# include "keys.h"
# include "error_messages.h"
# include "../mlx/mlx.h"

// CONSTANTS

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define ENEMY 'B'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define WIN_MSG "You won\n"

typedef struct s_point
{
    int	x;
    int	y;
}				t_point;

typedef struct s_tiles
{
    void	*wall;
    void	*floor;
    void	*player;
    void	*enemy;
    void	*collectible;
    void	*exit;
}		t_tiles;

typedef struct s_map
{
    char	**map;
    int		rows;
    int		columns;
    int		exit;
    int		collectibles;
    int		player;
    int		enemy;
    t_point	player_pos;
    t_point	*enemy_pos;
}		t_map;

typedef struct s_game
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_tiles	tiles;
    t_map	map;
    int		moves;
    int		animation_frame;
}		t_game;

/**
 * Creates and initializes a new game structure with default values
 */
static inline t_game	init_game(void)
{
    return ((t_game){
        .map.map = NULL,
        .map.rows = 0,
        .map.columns = 0,
        .map.collectibles = 0,
        .map.exit = 0,
        .map.player = 0,
        .map.enemy = 0,
        .tiles.collectible = NULL,
        .tiles.exit = NULL,
        .tiles.floor = NULL,
        .tiles.player = NULL,
        .tiles.enemy = NULL,
        .tiles.wall = NULL,
        .moves = -1,
        .animation_frame = 0,
    });
}

/**
 * Map loading and validation functions
 */
void	get_map(char *map_file, t_game *game);
void	validate_path(t_game *game);
void	map_check(t_game *game);

/**
 * MLX and rendering functions
 */
void	init_mlx(t_game *game);
void	render_map(t_game *game);
void	render_player_and_counter(t_game *game);
void	render_tiles(t_game *game);

/**
 * Game mechanics functions
 */
void	move_player(t_game *game, bool horizontal, int length);
void	move_enemy(t_game *game);
int		check_enemy_collision(t_game *game);
void	setup_game_hooks(t_game *game);
int		handle_key_press(int key, t_game *game);
int		quit_game(t_game *game);

/**
 * Utility functions
 */
void	write_error(t_game *game, char *error_msg);
void	destroy(t_game *game);
void	free_textures(t_game *game);
void	free_matrix(char **matrix);

#endif
