/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:08:02 by sutku             #+#    #+#             */
/*   Updated: 2023/03/17 00:01:05 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_pos(t_game *game, int i, int j)
{
	static int	k = 1;

	if (game->map_arr[i + k][j] == '1' || game->map_arr[i + k][j] == 'C'
			|| game->map_arr[i + k][j] == 'E')
		k *= -1;
	else
	{
		if (game->map_arr[i + k][j] == 'P')
		{
			game->game_state = -1;
			return ;
		}
		game->map_arr[i][j] = '0';
		game->map_arr[i + k][j] = 'X';
		game->en_idx[0] = i + k;
	}
}

void	enemy_move(t_game *game, int i, int j, int sec)
{
	char	*name;

	if (sec % 30 == 0)
		name = "./img/bomb1.xpm42";
	else if (sec % 15 == 0)
		name = "./img/bomb2.xpm42";
	if (game->game_state == 0)
	{
		if (sec % game->spd == 0)
			enemy_pos(game, i, j);
		game->imgs->en_one_img = put_image_to_map(game, name);
		if (mlx_image_to_window(game->mlx, game->imgs->en_one_img,
				j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	}
	return ;
}

void	enemy_hook(void *param)
{
	static int	sec = 0;
	t_game		*game;
	int			i;
	int			j;

	game = param;
	i = game->en_idx[0];
	j = game->en_idx[1];
	if (game->game_state == -1)
	{
		put_assets_to_images(game->imgs, game);
		return ;
	}
	if (sec % 15 == 0 && game->game_state == 0)
	{
		if (game->imgs->en_one_img)
			mlx_delete_image(game->mlx, game->imgs->en_one_img);
		enemy_move(game, i, j, sec);
	}
	sec++;
}

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
	t_string		str;

	if (argc != 2)
		error_message(ARGC_ERROR, &game);
	create_data(&game);
	measure_map(&game, argv[1]);
	put_map_to_arr(&game, argv[1]);
	read_map(&game);
	check_map(&game);
	mlx = mlx_init(game.width * 80, game.height * 80 + 100, "so_long", true);
	if (!mlx)
		return (EXIT_FAILURE);
	game.mlx = mlx;
	put_assets_to_images(&img, &game);
	string_to_map(&game, &str);
	mlx_loop_hook(game.mlx, &enemy_hook, &game);
	mlx_key_hook(game.mlx, &key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map_arr);
	// system("leaks sl_bonus");
	return (EXIT_SUCCESS);
}
