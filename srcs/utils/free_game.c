/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:14:03 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/11 23:36:47 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	free_game(char **game)
{
	size_t	i;

	i = 0;
	if (!game)
		return ;
	while (game[i])
	{
		free(game[i]);
		game[i] = NULL;
		i++;
	}
	if (i > 0)
		free(game);
	game = NULL;
}
