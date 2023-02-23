/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:06:38 by sutku             #+#    #+#             */
/*   Updated: 2023/02/23 17:20:01 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	y_check_win_lost(t_game *game)
{
	int	i;
	int	j;

	i = game->p_cur[0];
	j = game->p_cur[1];
	if (game->map_arr[i + game->p_move[0]][j] == '1' || game->map_arr[i + game->p_move[0]][j] == 'X')
		exit(printf("LOST"));
	if (game->map_arr[i + game->p_move[0]][j] == 'C')
	{
		game->collectable--;
		mlx_delete_image(game->mlx, game->imgs->c_img);
	}
	if (game->map_arr[i + game->p_move[0]][j] != 'E' && game->collectable == 0)
	{
		game->exist_msg = 1;
		game->msg = mlx_put_string(game->mlx, "MESSAGE : Lets go home !", 10, (game->height) * 80 + 50);
	}
	if (game->map_arr[i + game->p_move[0]][j] == 'E' && game->collectable != 0)
	{	
		game->exist_msg = 1;
		game->msg = mlx_put_string(game->mlx, "MESSAGE : I need more radishes", 10, (game->height) * 80 + 50);
	}
	if (game->map_arr[i + game->p_move[0]][j] == 'E' && game->collectable == 0)
		exit(printf("WIN"));
}

void	x_check_win_lost(t_game *game)
{
	int	i;
	int	j;

	i = game->p_cur[0];
	j = game->p_cur[1];
	if (game->map_arr[i][j + game->p_move[1]] == '1' || game->map_arr[i][j + game->p_move[1]] == 'X')
		exit(printf("LOST"));
	if (game->map_arr[i][j + game->p_move[1]] == 'C')
	{
		game->collectable--;
		mlx_delete_image(game->mlx, game->imgs->c_img);
	}
	if (game->map_arr[i][j + game->p_move[1]] != 'E' && game->collectable == 0)
	{
		game->exist_msg = 1;
		game->msg = mlx_put_string(game->mlx, "MESSAGE : Lets go home !", 10, (game->height) * 80 + 50);
	}
	if (game->map_arr[i][j + game->p_move[1]] == 'E' && game->collectable != 0)
	{
		game->exist_msg = 1;
		game->msg = mlx_put_string(game->mlx, "MESSAGE : I need more radishes", 10, (game->height) * 80 + 60);
	}	
	if (game->map_arr[i][j + game->p_move[1]] == 'E' && game->collectable == 0)
		exit(printf("WIN"));
}

void	move(t_game *game)
{
	int	i;
	int	j;

	i = game->p_cur[0];
	j = game->p_cur[1];
	delete_strings(game);
	if (game->exist_msg == 1)
		mlx_delete_image(game->mlx, game->msg);
	game->exist_msg = 0;
	if (game->p_move[0] != 0 && game->game_state == 0)
	{
		y_check_win_lost(game);
		if (game->map_arr[i + game->p_move[0]][j] != 'E')
		{
			game -> map_arr[i + game->p_move[0]][j] = 'P';
			game->p_cur[0] = i + game->p_move[0];
			game -> map_arr[i][j] = '0';
			mlx_delete_image(game->mlx, game->p_img);
			game ->p_num_mov++;
		}
	}
	if (game->p_move[1] != 0 && game->game_state == 0)
	{
		x_check_win_lost(game);
		if (game->map_arr[i][j + game->p_move[1]] != 'E')
		{
			game->map_arr[i][j + game->p_move[1]] = 'P';
			game->p_cur[1] = j + game->p_move[1];
			game->map_arr[i][j] = '0';
			mlx_delete_image(game->mlx, game->p_img);
			game->p_num_mov++;
		}
	}
	string_to_map(game);
	put_assets_to_images(game->mlx, game->imgs, game);
	put_assets_to_map(game->mlx, game, game->imgs);
	game->p_move[0] = 0;
	game->p_move[1] = 0;
	return ;
}

void	my_hook(mlx_key_data_t k_data, void *param)
{
	t_game		*game;

	game = param;
	game->p_move[0] = 0;
	game->p_move[1] = 0;
	if (k_data.action == MLX_PRESS)
	{
		if (k_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (k_data.key == MLX_KEY_UP)
		{
			game->p_move[0] = -1;
			move(game);
		}
		if (k_data.key == MLX_KEY_DOWN)
		{
			game->p_move[0] = 1;
			move(game);
		}
		if (k_data.key == MLX_KEY_LEFT)
		{
			game->p_move[1] = -1;
			move(game);
		}
		if (k_data.key == MLX_KEY_RIGHT)
		{
			game->p_move[1] = 1;
			move(game);
		}
	}	
}
