/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:06:38 by sutku             #+#    #+#             */
/*   Updated: 2023/03/05 04:33:07 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_hook(mlx_key_data_t k_data, void *param)
{
	t_game		*game;

	game = param;
	if (k_data.action == MLX_PRESS)
	{
		if (k_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (k_data.key == MLX_KEY_UP || k_data.key == MLX_KEY_W)
			move_up(game, game->p_cur[0] , game->p_cur[1]);
		if (k_data.key == MLX_KEY_DOWN || k_data.key == MLX_KEY_S)
			move_down(game, game->p_cur[0], game->p_cur[1]);
		if (k_data.key == MLX_KEY_LEFT || k_data.key == MLX_KEY_A)
			move_left(game, game->p_cur[0], game->p_cur[1]);
		if (k_data.key == MLX_KEY_RIGHT || k_data.key == MLX_KEY_D)
			move_right(game, game->p_cur[0], game->p_cur[1]);
	}	
}
