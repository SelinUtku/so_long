/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:26:41 by sutku             #+#    #+#             */
/*   Updated: 2023/03/03 14:39:42 by sutku            ###   ########.fr       */
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
	game->drc = 0;
	game->str = NULL;
}

void	string_to_map(t_game *game, t_string *str)
{
	if (game->str != NULL)
	{
		game->old_str = game->str;
		delete_strings(game->mlx, game->old_str);	
	}
	if (game->game_state != -1 && game->game_state != 1)
	{
		game->mov_arr =  ft_itoa(game->p_num_mov);
		game->rem_c_arr = ft_itoa(game->collectable);
		str->score = mlx_put_string(game->mlx, "MOVES : ", 10, (game->height) * 80 + 10);
		str->score_point = mlx_put_string(game->mlx, game->mov_arr, 100, (game->height) * 80 + 10);
		str->num_col = mlx_put_string(game->mlx, "REMAIN_RADISH : ",10, (game->height) * 80 + 30);
		str->remain_col = mlx_put_string(game->mlx, game->rem_c_arr, 170, (game->height) * 80 + 30);
		game->str = str;	
	}
}

void	delete_strings(mlx_t *mlx, t_string *old_str)
{
	mlx_delete_image(mlx, old_str->score);
	mlx_delete_image(mlx, old_str->score_point);
	mlx_delete_image(mlx, old_str->num_col);
	mlx_delete_image(mlx, old_str->remain_col);
}