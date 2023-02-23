/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:26:41 by sutku             #+#    #+#             */
/*   Updated: 2023/02/23 17:12:23 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_data(t_game *game)
{
	game->collectable = 0;
	game->player = 0;
	game->enemy = 0;
	game->e_xit = 0;
	game->width = 0;
	game->height = 0;
	game->map_arr = NULL;
	game->p_num_mov = 0;
	game->exist_msg = 0;
	game->game_state = 0;
}

void	string_to_map(t_game *game)
{
	game->mov_arr =  ft_itoa(game->p_num_mov);
	game->rem_c_arr = ft_itoa(game->collectable);
	game->imgs->score = mlx_put_string(game->mlx, "MOVES : ", 10, (game->height) * 80 + 10);
	game->imgs->score_point = mlx_put_string(game->mlx, game->mov_arr, 100, (game->height) * 80 + 10);
	game->imgs->num_col = mlx_put_string(game->mlx, "REMAIN_RADISH : ",10, (game->height) * 80 + 30);
	game->imgs->remain_col = mlx_put_string(game->mlx, game->rem_c_arr, 170, (game->height) * 80 + 30);
}

void	delete_strings(t_game *game)
{
	mlx_delete_image(game->mlx, game->imgs->score);
	mlx_delete_image(game-> mlx, game->imgs->score_point);
	mlx_delete_image(game-> mlx, game->imgs->num_col);
	mlx_delete_image(game->mlx, game->imgs->remain_col);
}