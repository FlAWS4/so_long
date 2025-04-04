/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:00:59 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/11 23:40:06 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_textures(t_game *game)
{
	if (game->tiles.wall)
		mlx_destroy_image(game->mlx_ptr, game->tiles.wall);
	if (game->tiles.floor)
		mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
	if (game->tiles.player)
		mlx_destroy_image(game->mlx_ptr, game->tiles.player);
	if (game->tiles.collectible)
		mlx_destroy_image(game->mlx_ptr, game->tiles.collectible);
	if (game->tiles.exit)
		mlx_destroy_image(game->mlx_ptr, game->tiles.exit);
}

void	destroy(t_game *game)
{
	if (!game)
		return ;
	free_textures(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.map)
		free_game(game->map.map);
}
