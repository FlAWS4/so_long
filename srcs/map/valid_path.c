/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:03:50 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/08 23:11:47 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**create_blank_grid(t_game *game)
{
    char	**grid;
    int     row;

    grid = ft_calloc(game->map.rows + 1, sizeof(char *));
    if (!grid)
        write_error(game, MALLOC_ERR);
    row = 0;
    while (row < game->map.rows)
    {
        grid[row] = ft_strdup(game->map.map[row]);
        if (!grid[row])
        {
            free_matrix(grid);
            write_error(game, MALLOC_ERR);
        }
        row++;
    }
    return (grid);
}

static void	perform_flood_fill(t_map *map, t_point position, char **grid, int *collected_coins, bool *exit_found)
{
    if (position.y < 0 || position.y >= map->rows || position.x < 0 || position.x >= map->columns)
        return;
    if (grid[position.y][position.x] == WALL || grid[position.y][position.x] == 'V')
        return;
    if (grid[position.y][position.x] == COLLECTIBLE)
    {
        (*collected_coins)++;
        printf("Collected a coin at: (%d, %d)\n", position.x, position.y); // Debug print
    }
    if (grid[position.y][position.x] == EXIT)
    {
        if (*collected_coins == map->collectibles)
        {
            *exit_found = true;
            printf("Exit found at: (%d, %d) after collecting all coins\n", position.x, position.y); // Debug print
        }
        else
        {
            printf("Exit found at: (%d, %d) but not all coins collected\n", position.x, position.y); // Debug print
        }
        return;
    }
    grid[position.y][position.x] = 'V'; // Mark the cell as visited
    printf("Visiting: (%d, %d)\n", position.x, position.y); // Debug print
    perform_flood_fill(map, (t_point){position.x + 1, position.y}, grid, collected_coins, exit_found);
    perform_flood_fill(map, (t_point){position.x - 1, position.y}, grid, collected_coins, exit_found);
    perform_flood_fill(map, (t_point){position.x, position.y + 1}, grid, collected_coins, exit_found);
    perform_flood_fill(map, (t_point){position.x, position.y - 1}, grid, collected_coins, exit_found);
}

void	validate_path(t_game *game)
{
    char	**grid;
    int		collected_coins;
    bool	exit_found;

    collected_coins = 0;
    exit_found = false;
    grid = create_blank_grid(game);
    perform_flood_fill(&game->map, game->map.player_pos, grid, &collected_coins, &exit_found);
    printf("Total collected coins: %d, Total required coins: %d\n", collected_coins, game->map.collectibles); // Debug print
    printf("Exit found: %s\n", exit_found ? "true" : "false"); // Debug print
    if (collected_coins != game->map.collectibles || !exit_found)
    {
        free_matrix(grid);
        write_error(game, "Invalid map: Unreachable collectibles or exit.");
    }
    free_matrix(grid);
}
