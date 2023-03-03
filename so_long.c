/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:02 by sutku             #+#    #+#             */
/*   Updated: 2023/03/03 20:17:11 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(t_game *game, int i, int j, int sec)
{
	char	*name;
	static int	incr = -1;// staticleri ayri yazinca bozuluyor aq

	if (sec % 20 == 0)
		name = "./img/bomb1.xpm42";
	if (sec % 40 == 0)
		name = "./img/bomb2.xpm42";
	if (game->game_state == 0)
	{
		if (sec % 120 == 0)
		{
			if (game->map_arr[i + incr][j] == '1')
				incr *= -1;
			i += incr;
			if (game->map_arr[i][j] == 'P')
			{
				game->game_state = -1;
				return ;
			}
			game->map_arr[i - incr][j] = '0';
			game->map_arr[i][j] = 'X';
			game->en_idx[0] = i;
		}
		game -> imgs->en_one_img = put_image_to_map(game -> mlx, name);
		if (mlx_image_to_window(game->mlx, game->imgs->en_one_img, j * 80 , i * 80) < 0)
			error_message(MLX_IMG_WND);
	}
	return ;
}

void	hook(void *param)
{
	static int sec = 0;
	t_game	*game;
	int	i;
	int j;

	game = param;
	i = game->en_idx[0];
	j = game->en_idx[1];
	if (game->game_state == -1)
	{
		put_assets_to_images(game->mlx, game->imgs, game);
		return ;
	}
	if (sec % 20 == 0 && game->game_state == 0)
	{
		if (game->imgs->en_one_img)
			mlx_delete_image(game->mlx, game->imgs->en_one_img);
		enemy_move(game, i, j, sec);
	}
	sec++;
}

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
	mlx = mlx_init(game.width * 80, game.height * 80 + 100 , "so_long", true);
	if (!mlx)
		return (EXIT_FAILURE);
	game.mlx = mlx;
	put_assets_to_images(game.mlx, &img, &game);
	put_assets_to_map(game.mlx, &game, &img);
	string_to_map(&game, &str);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_key_hook(game.mlx, &my_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
