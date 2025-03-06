/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:05:57 by my42              #+#    #+#             */
/*   Updated: 2025/03/06 19:55:48 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**create_blank_grid(t_game *game)
{
    char	**grid;
    int		row;

    grid = ft_calloc(game->map.rows + 1, sizeof(char *));
    if (!grid)
        panic(game, MALLOC_ERR);
    row = 0;
    while (row < game->map.rows)
    {
        grid[row] = ft_strdup(game->map.map[row]);
        if (!grid[row])
        {
            free_matrix(grid);
            panic(game, MALLOC_ERR);
        }
        row++;
    }
    return (grid);
}

static bool	perform_flood_fill(t_map *map, t_point position, char **grid, int *collected_coins, bool *exit_found)
{
    if (grid[position.y][position.x] == WALL)
        return (false);
    if (grid[position.y][position.x] == COLLECTIBLE)
        (*collected_coins)++;
    if (grid[position.y][position.x] == EXIT)
        *exit_found = true;
    grid[position.y][position.x] = WALL;
    perform_flood_fill(map, (t_point){position.x + 1, position.y}, grid, collected_coins, exit_found);
    perform_flood_fill(map, (t_point){position.x - 1, position.y}, grid, collected_coins, exit_found);
    perform_flood_fill(map, (t_point){position.x, position.y + 1}, grid, collected_coins, exit_found);
    perform_flood_fill(map, (t_point){position.x, position.y - 1}, grid, collected_coins, exit_found);
    return (*collected_coins == map->collectibles && *exit_found);
}

void	validate_path(t_game *game)
{
    char	**grid;
    int		collected_coins;
    bool	exit_found;

    collected_coins = 0;
    exit_found = false;
    grid = create_blank_grid(game);
    if (!perform_flood_fill(&game->map, game->map.player_pos, grid, &collected_coins, &exit_found))
    {
        free_matrix(grid);
        panic(game, UNACHIEVABLE_ENTITIES);
    }
    free_matrix(grid);
}
