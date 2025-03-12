/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:03:37 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/11 23:38:46 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

#define VALID_ENTITIES "ECP01"

static void	validate_entity_counts(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		write_error(game, INVALID_NBR_EXITS);
	if (game->map.collectibles == 0)
		write_error(game, NO_COLLECTIBLES);
	if (game->map.player == 0 || game->map.player > 1)
		write_error(game, INVALID_NBR_PLAYERS);
}

static void	count_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (!is_onstr(VALID_ENTITIES, game->map.map[i][j]))
				write_error(game, INVALID_ENTITY);
			if (game->map.map[i][j] == EXIT)
				game->map.exit += 1;
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->map.collectibles += 1;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){j, i};
			}
		}
	}
	validate_entity_counts(game);
}

static bool	is_map_surrounded(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		if (map->map[i][0] != WALL || map->map[i][map->columns - 1] != WALL)
			return (false);
	i = -1;
	while (++i < map->columns)
		if (map->map[0][i] != WALL || map->map[map->rows - 1][i] != WALL)
			return (false);
	return (true);
}

static bool	is_map_rectangular(t_game *game)
{
	size_t	len;
	size_t	i;

	len = game->map.columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (len != ft_strlen(game->map.map[i]))
			return (false);
		i++;
	}
	return (true);
}

void	map_check(t_game *game)
{
	if (!is_map_rectangular(game))
		write_error(game, INVALID_FORMAT);
	count_map_elements(game);
	if (!is_map_surrounded(&game->map))
		write_error(game, MAP_NOT_CLOSED);
	validate_path(game);
}
