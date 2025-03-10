/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:59:13 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/10 10:18:43 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * Validates command line arguments for proper format
 * Ensures a valid map file is provided
 *
 * @param argc Argument count from command line
 * @param argv Argument values from command line
 */
static void	validate_arguments(int argc, char **argv)
{
    if (argc != 2)
        write_error(NULL, INVALID_NBR_ARGS);
    if (*argv[1] == '\0')
        write_error(NULL, NULL_MAP);
}

/**
 * Main entry point for the game
 * Initializes game components, loads map, and starts game loop
 *
 * @param argc Argument count from command line
 * @param argv Argument values from command line
 * @return EXIT_SUCCESS if game terminates properly
 */
int	main(int argc, char **argv)
{
    t_game	game;

    validate_arguments(argc, argv);
    game = init_game();
    get_map(argv[1], &game);
    map_check(&game);
    init_mlx(&game);
    render_map(&game);
    setup_game_hooks(&game);
    return (EXIT_SUCCESS);
}