/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:21 by my42              #+#    #+#             */
/*   Updated: 2025/03/06 01:23:09 by my42             ###   ########.fr       */
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

typedef struct s_point {
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
    t_point	enemy_pos;
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
void	get_map(char *map_file, t_game *game);
/*	Checks if the map has a valid exit path
and if all entities are achievable */
void	validate_path(t_game *game);
void	map_check(t_game *game);

/* Initializes mlx and win pointers*/
void	init_mlx(t_game *game);

/* Renders the respective tiles according to the characters on the map */
void	render_map(t_game *game);

void	update_player_pos(t_game *game, bool horizontal, int length);
/* Renders player tile and moves counter */
void	put_player_tile(t_game *game);
void	put_enemy_tile(t_game *game);

void	hook_n_run(t_game *game);

int		quit_game(t_game *game);

/* UTILS */

/* Calls destroy() and exits the program on FAILURE */
void	panic(t_game *game, char *error_msg);

/* Destroys game ptr and all its inside fields */
void	destroy(t_game *game);

/* Frees matrix ptr and all its inside fields */
void	free_matrix(char **matrix);

/* Animation function */
int		animate(t_game *game);

#endif