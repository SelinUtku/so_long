/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:02 by sutku             #+#    #+#             */
/*   Updated: 2023/03/16 23:59:14 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t k_data, void *param)
{
	t_game		*game;

	game = param;
	if (k_data.action == MLX_PRESS)
	{
		if (k_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (game->game_state == 0 && (k_data.key == MLX_KEY_UP
				|| k_data.key == MLX_KEY_W))
			move_up(game, game->p_cur[0], game->p_cur[1]);
		if (game->game_state == 0 && (k_data.key == MLX_KEY_DOWN
				|| k_data.key == MLX_KEY_S))
			move_down(game, game->p_cur[0], game->p_cur[1]);
		if (game->game_state == 0 && (k_data.key == MLX_KEY_LEFT
				|| k_data.key == MLX_KEY_A))
			move_left(game, game->p_cur[0], game->p_cur[1]);
		if (game->game_state == 0 && (k_data.key == MLX_KEY_RIGHT
				|| k_data.key == MLX_KEY_D))
			move_right(game, game->p_cur[0], game->p_cur[1]);
	}	
}

int32_t	main(int argc, char **argv)
{
	t_game			game;
	mlx_t			*mlx;
	t_images		img;

	if (argc != 2)
		error_message(ARGC_ERROR, &game);
	create_data(&game);
	measure_map(&game, argv[1]);
	put_map_to_arr(&game, argv[1]);
	read_map(&game);
	check_map(&game);
	mlx = mlx_init(game.width * 80, game.height * 80, "so_long", true);
	if (!mlx)
		return (EXIT_FAILURE);
	game.mlx = mlx;
	put_assets_to_images(&img, &game);
	mlx_key_hook(game.mlx, &key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map_arr);
	// system("leaks so_long");
	return (EXIT_SUCCESS);
}
