/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:59:13 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/08 21:52:58 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	args_check(int argc, char **argv)
{
	if (argc != 2)
		write_error(NULL, INVALID_NBR_ARGS);
	if (*argv[1] == '\0')
		write_error(NULL, NULL_MAP);
}

int	main(int argc, char **argv)
{
	t_game	game;

	args_check(argc, argv);
	game = init_game();
	get_map(argv[1], &game);
	map_check(&game);
	init_mlx(&game);
	render_map(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
