/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:02 by sutku             #+#    #+#             */
/*   Updated: 2023/02/26 16:04:18 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1600//16*20*5
#define HEIGHT 900//16*10*5

int32_t	main(int argc, char **argv)
{
	t_game			game;
	mlx_t			*mlx;
	t_images		img;
	t_string		str;

	if (argc != 2)
		error_message(ARGC_ERROR);
	create_data(&game);
	measure_map(&game, argv[1]);
	put_map_to_arr(&game, argv[1]);
	read_map(&game);
	check_map(&game);
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		return (EXIT_FAILURE);
	game.mlx = mlx;
	put_assets_to_images(game.mlx, &img, &game);
	put_assets_to_map(game.mlx, &game, &img);
	string_to_map(&game, &str);
	mlx_key_hook(game.mlx, &my_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
