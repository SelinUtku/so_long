/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:45:54 by sutku             #+#    #+#             */
/*   Updated: 2023/03/16 23:55:56 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wlc(t_game *game, int i, int j)
{
	if (game->map_arr[i][j] == 'E' && game->collectable == 0)
		game->game_state = 1;
	if (game->map_arr[i][j] == 'C')
		game->collectable--;
	if (game->map_arr[i][j] == 'E' && game->collectable != 0)
		ft_printf("MESSAGE : I need more radishes\n");
}

void	move_up(t_game *game, int i, int j)
{
	check_wlc(game, i - 1, j);
	if (game->map_arr[i - 1][j] != 'E'
			&& game->map_arr[i - 1][j] != '1')
	{
		game->map_arr[i - 1][j] = 'P';
		game->p_cur[0] = i - 1;
		game->map_arr[i][j] = '0';
		game->drc = 1;
		game->p_num_mov++;
		if (game->game_state == 0)
			ft_printf("MOVES : %d\n", game->p_num_mov);
	}
	put_assets_to_images(game->imgs, game);
	return ;
}

void	move_down(t_game *game, int i, int j)
{
	check_wlc(game, i + 1, j);
	if (game->map_arr[i + 1][j] != 'E' && game->map_arr[i + 1][j] != '1')
	{
		game->map_arr[i + 1][j] = 'P';
		game->p_cur[0] = i + 1;
		game->map_arr[i][j] = '0';
		game->drc = 0;
		game->p_num_mov++;
		if (game->game_state == 0)
			ft_printf("MOVES : %d\n", game->p_num_mov);
	}
	put_assets_to_images(game->imgs, game);
	return ;
}

void	move_left(t_game *game, int i, int j)
{
	check_wlc(game, i, j - 1);
	if (game->map_arr[i][j - 1] != 'E' && game->map_arr[i][j - 1] != '1')
	{
		game->map_arr[i][j - 1] = 'P';
		game->p_cur[1] = j - 1;
		game->map_arr[i][j] = '0';
		game->drc = 2;
		game->p_num_mov++;
		if (game->game_state == 0)
			ft_printf("MOVES : %d\n", game->p_num_mov);
	}
	put_assets_to_images(game->imgs, game);
	return ;
}

void	move_right(t_game *game, int i, int j)
{
	check_wlc(game, i, j + 1);
	if (game->map_arr[i][j + 1] != 'E' && game->map_arr[i][j + 1] != '1')
	{
		game->map_arr[i][j + 1] = 'P';
		game->p_cur[1] = j + 1;
		game->map_arr[i][j] = '0';
		game->drc = 3;
		game->p_num_mov++;
		if (game->game_state == 0)
			ft_printf("MOVES : %d\n", game->p_num_mov);
	}
	put_assets_to_images(game->imgs, game);
	return ;
}
