/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:45:54 by sutku             #+#    #+#             */
/*   Updated: 2023/03/03 18:35:19 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wlc(t_game *game, int i, int j)
{
	if (game->map_arr[i][j] == 'X')
		game->game_state = -1;
	if (game->map_arr[i][j] == 'C')
		game->collectable--;
	if (game->map_arr[i][j] != 'E' && game->collectable == 0)
	{
		game->exist_msg = 1;
		game->msg = mlx_put_string(game->mlx, "MESSAGE : Lets go home !", 10, (game->height) * 80 + 50);
	}
	if (game->map_arr[i][j] == 'E' && game->collectable != 0)
	{	
		game->exist_msg = 1;
		game->msg = mlx_put_string(game->mlx, "MESSAGE : I need more radishes", 10, (game->height) * 80 + 50);
	}
	if (game->map_arr[i][j] == 'E' && game->collectable == 0)
		game->game_state = 1;
}

void	move_up(t_game *game, int i, int j)
{
	check_wlc(game, i - 1, j);
	if (game->game_state != -1 && game->map_arr[i - 1][j] != 'E' && game->map_arr[i - 1][j] != '1')
	{
		game->map_arr[i - 1][j] = 'P';
		game->p_cur[0] = i - 1;
		game->map_arr[i][j] = '0';
		game->drc = 1;
		game->p_num_mov++;
	}
	put_assets_to_images(game->mlx, game->imgs, game);
	string_to_map(game, game->str);
	return ;
}

void	move_down(t_game *game, int i, int j)
{
	check_wlc(game, i + 1, j);
	if (game->game_state != -1 && game->map_arr[i + 1][j] != 'E' && game->map_arr[i + 1][j] != '1')
	{
		game->map_arr[i + 1][j] = 'P';
		game->p_cur[0] = i + 1;
		game->map_arr[i][j] = '0';
		game->drc = 0;
		game->p_num_mov++;
	}
	put_assets_to_images(game->mlx, game->imgs, game);
	string_to_map(game, game->str);
	return ;
}

void	move_left(t_game *game, int i, int j)
{
	check_wlc(game, i, j - 1);
	if (game->game_state != -1 && game->map_arr[i][j - 1] != 'E' && game->map_arr[i][j - 1] != '1')
	{
		game->map_arr[i][j - 1] = 'P';
		game->p_cur[1] = j - 1;
		game->map_arr[i][j] = '0';
		game->drc = 2;
		game->p_num_mov++;
	}
	put_assets_to_images(game->mlx, game->imgs, game);
	string_to_map(game, game->str);
	return ;
}

void	move_right(t_game *game, int i, int j)
{
	check_wlc(game, i, j + 1);
	if (game->game_state != -1 && game->map_arr[i][j + 1] != 'E' && game->map_arr[i][j + 1] != '1')
	{
		game->map_arr[i][j + 1] = 'P';
		game->p_cur[1] = j + 1;
		game->map_arr[i][j] = '0';
		game->drc = 3;
		game->p_num_mov++;
	}
	put_assets_to_images(game->mlx, game->imgs, game);
	string_to_map(game, game->str);
	return ;
}
