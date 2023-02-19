/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:02 by sutku             #+#    #+#             */
/*   Updated: 2023/02/19 16:25:45 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1440//16*18*5
#define HEIGHT 720//16*8*5

int32_t	main(void)
{
	t_map			map;
	t_player		player;
	xpm_t			*bg;
	mlx_t			*mlx;
	mlx_image_t		*img;

	create_data(&map, &player);
	measure_map(&map, "./map/map.ber");
	put_map_to_arr(&map, &player, "./map/map.ber");
	read_map(&map, &player);
	check_map(&map, &player);

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		error_message("No mlx");
	if(open_image("./img/background.xpm42") == -1)
		return(-1);
	bg = mlx_load_xpm42("./img/background.xpm42");
	if (!bg)
		return(-1);
	img = mlx_texture_to_image(mlx, &bg->texture);
	if(!img)
		return(-1);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error_message("no image on window");
	mlx_loop(mlx);
	mlx_delete_xpm42(bg);
	return (EXIT_SUCCESS);
}
