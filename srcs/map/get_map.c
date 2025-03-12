/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:03:01 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/11 23:43:46 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * Checks if the file has a valid .ber extension
 */
static bool	is_valid_extension(char *map_file)
{
	size_t	len;

	len = ft_strlen(map_file);
	if (len < 4)
		return (false);
	if (ft_strncmp(".ber", &map_file[len - 4], 4) == 0)
		return (true);
	return (false);
}

/**
 * Counts the number of rows in the map file
 */
static void	count_file_rows(char *map_file, t_game *game)
{
	int		row_count;
	int		map_fd;
	char	*line;

	row_count = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		write_error(game, OPEN_MAP_FILE_ERR);
	line = get_next_line(map_fd);
	while (line)
	{
		row_count++;
		free(line);
		line = get_next_line(map_fd);
	}
	if (row_count == 0)
		write_error(game, EMPTY_MAP_FILE);
	game->map.rows = row_count;
	close(map_fd);
}

/**
 * Reads the map content from the file
 */
static void	read_map_lines(char *map_file, t_game *game)
{
	int	map_fd;
	int	i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		write_error(game, OPEN_MAP_FILE_ERR);
	i = 0;
	while (i < game->map.rows)
		game->map.map[i++] = get_next_line(map_fd);
	game->map.map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (game->map.rows - 1))
	{
		game->map.map[i] = ft_strtrim(game->map.map[i], "\n");
		if (!game->map.map[i])
			write_error(game, MALLOC_ERR);
		i++;
	}
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	get_map(char *map_file, t_game *game)
{
	if (!is_valid_extension(map_file))
		write_error(game, INVALID_MAP_FILE);
	count_file_rows(map_file, game);
	game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
	if (!game->map.map)
		write_error(game, MALLOC_ERR);
	read_map_lines(map_file, game);
}
