/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:06:38 by sutku             #+#    #+#             */
/*   Updated: 2023/02/22 20:40:14 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	move_up(t_game *game)
{
	int	i;
	int	j;

	i = game->p_cur[0];
	j = game->p_cur[1];
	if (game->p_move[0] != 0)
	{
		if (game->map_arr[i + game->p_move[0]][j] == '1' || game->map_arr[i + game->p_move[0]][j] == 'X')
			exit(printf("LOST"));
		game -> map_arr[i + game->p_move[0]][j] = 'P';
		game->p_cur[0] = i + game->p_move[0];
		game -> map_arr[i][j] = '0';
		game ->p_num_mov++;
		// mlx_delete_image(game->mlx, game->p_img);
		// put_assets_to_map(game->mlx, game, game->imgs);
	}
	if (game->p_move[1] != 0)
	{
		if (game->map_arr[i][j + game->p_move[1]] == '1' || game->map_arr[i][j + game->p_move[1]] == 'X')
			exit(printf("LOST"));
		game->map_arr[i][j + game->p_move[1]] = 'P';
		game->p_cur[1] = j + game->p_move[1];
		game->map_arr[i][j] = '0';
		game->p_num_mov++;
		// put_assets_to_map(game->mlx, game, game-> imgs);
	}
	game->p_move[0] = 0;
	game->p_move[1] = 0;
	return ;
}

void	my_hook(mlx_key_data_t k_data, void *param)
{
	t_game		*ply;

	ply = param;
	ply->p_move[0] = 0;
	ply->p_move[1] = 0;
	if (k_data.action == MLX_PRESS)
	{
		if (k_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(ply->mlx);
		if (k_data.key == MLX_KEY_UP)
		{
			ply->p_move[0] = -1;
			move_up(ply);
			ply->p_img->instances[0].y -= 80;
		}
		if (k_data.key == MLX_KEY_DOWN)
		{
			ply->p_move[0] = 1;
			move_up(ply);
			ply->p_img->instances[0].y += 80;
		}
		if (k_data.key == MLX_KEY_LEFT)
		{
			ply->p_move[1] = -1;
			move_up(ply);
			ply->p_img->instances[0].x -= 80;
		}
		if (k_data.key == MLX_KEY_RIGHT)
		{
			ply->p_move[1] = 1;
			move_up(ply);
			ply->p_img->instances[0].x += 80;
		}
	}	
}