/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:02 by sutku             #+#    #+#             */
/*   Updated: 2023/02/20 16:30:30 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1600//16*20*5
#define HEIGHT 880//16*10*5

int32_t	main(void)
{
	t_map			map;
	t_player		player;
	mlx_t			*mlx;

	create_data(&map, &player);
	measure_map(&map, "./map/map.ber");
	put_map_to_arr(&map, &player, "./map/map.ber");
	read_map(&map, &player);
	check_map(&map, &player);
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		return(EXIT_FAILURE);
	put_bg_to_map(&map, mlx);
	player_image(&map, mlx, &player);
	mlx_key_hook(mlx, &my_hook, &player);
	mlx_loop(mlx);
	//close_images();
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
