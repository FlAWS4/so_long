/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:03:50 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/10 14:36:15 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:03:50 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/09 21:24:27 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * Creates a copy of the map for path validation
 * Used to avoid modifying the original map during flood fill
 */
static char	**create_map_copy(t_game *game)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!grid)
		write_error(game, MALLOC_ERR);
	while (i < game->map.rows)
	{
		grid[i] = ft_strdup(game->map.map[i]);
		if (!grid[i])
		{
			free_game(grid);
			write_error(game, MALLOC_ERR);
		}
		i++;
	}
	return (grid);
}

/**
 * Modified flood fill algorithm that treats EXIT as a wall
 * This ensures collectibles aren't placed behind exits
 */
static void	flood_fill_collectibles(char **grid, int x,
		int y, int *collect_count)
{
	if (y < 0 || grid[y] == NULL || x < 0 || grid[y][x] == '\0'\
		|| grid[y][x] == WALL || grid[y][x] == EXIT || grid[y][x] == 'V')
		return ;
	if (grid[y][x] == COLLECTIBLE)
		(*collect_count)++;
	grid[y][x] = 'V';
	flood_fill_collectibles(grid, x + 1, y, collect_count);
	flood_fill_collectibles(grid, x - 1, y, collect_count);
	flood_fill_collectibles(grid, x, y + 1, collect_count);
	flood_fill_collectibles(grid, x, y - 1, collect_count);
}

/**
 * Regular flood fill to check if exit is reachable
 */
static bool	check_exit_reachable(char **grid, int x, int y)
{
	static bool	exit_found = false;

	if (y < 0 || grid[y] == NULL || x < 0 || grid[y][x] == '\0'
		|| grid[y][x] == WALL || grid[y][x] == 'V' || exit_found)
		return (exit_found);
	if (grid[y][x] == EXIT)
		exit_found = true;
	grid[y][x] = 'V';
	check_exit_reachable(grid, x + 1, y);
	check_exit_reachable(grid, x - 1, y);
	check_exit_reachable(grid, x, y + 1);
	check_exit_reachable(grid, x, y - 1);
	return (exit_found);
}

/**
 * Validates that there exists a valid path from the player's position
 * to all collectibles and the exit
 */
void	validate_path(t_game *game)
{
	char	**grid1;
	char	**grid2;
	int		collectibles_found;

	collectibles_found = 0;
	grid1 = create_map_copy(game);
	flood_fill_collectibles(grid1, game->map.player_pos.x,
		game->map.player_pos.y, &collectibles_found);
	if (collectibles_found != game->map.collectibles)
	{
		free_game(grid1);
		write_error(game, UNACHIEVABLE_ENTITIES);
	}
	free_game(grid1);
	grid2 = create_map_copy(game);
	if (!check_exit_reachable(grid2, game->map.player_pos.x,
			game->map.player_pos.y))
	{
		free_game(grid2);
		write_error(game, UNACHIEVABLE_ENTITIES);
	}
	free_game(grid2);
}
