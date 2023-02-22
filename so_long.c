/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:02 by sutku             #+#    #+#             */
/*   Updated: 2023/02/22 20:20:39 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1600//16*20*5
#define HEIGHT 880//16*10*5

int32_t	main(void)
{
	t_game			game;
	mlx_t			*mlx;
	t_images		img;

	game.mlx = mlx;
	create_data(&game);
	measure_map(&game, "./map/map.ber");
	put_map_to_arr(&game, "./map/map.ber");
	read_map(&game);
	check_map(&game);
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		return (EXIT_FAILURE);
	put_assets_to_images(mlx, &img, &game);
	put_assets_to_map(mlx, &game, &img);
	mlx_key_hook(mlx, &my_hook, &game);
	mlx_loop(mlx);
	// close_images();
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
