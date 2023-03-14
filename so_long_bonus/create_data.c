/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:26:41 by sutku             #+#    #+#             */
/*   Updated: 2023/03/14 20:23:48 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_data(t_game *game)
{
	game->collectable = 0;
	game->player = 0;
	game->enemy = 0;
	game->e_xit = 0;
	game->width = 0;
	game->height = 0;
	game->spd = 75;
	game->map_arr = NULL;
	game->p_num_mov = 0;
	game->exist_msg = 0;
	game->game_state = 0;
	game->drc = 0;
	game->str = NULL;
	game->imgs = NULL;
	game->old_images = NULL;
	game->old_str = NULL;
	game->mov_arr = NULL;
	game->rem_c_arr = NULL;
}

void	string_to_map(t_game *game, t_string *str)
{
	if (game->str != NULL)
	{
		game->old_str = game->str;
		delete_strings(game->mlx, game->old_str, game);
	}
	if (game->game_state != -1 && game->game_state != 1)
	{
		game->mov_arr = ft_itoa(game->p_num_mov);
		game->rem_c_arr = ft_itoa(game->collectable);
		str->score = mlx_put_string(game->mlx, "MOVES : ",
				10, (game->height) * 80 + 10);
		str->score_point = mlx_put_string(game->mlx, game->mov_arr,
				100, (game->height) * 80 + 10);
		str->num_col = mlx_put_string(game->mlx, "REMAIN_RADISH : ",
				10, (game->height) * 80 + 30);
		str->remain_col = mlx_put_string(game->mlx, game->rem_c_arr,
				170, (game->height) * 80 + 30);
		game->str = str;
	}
}

void	delete_strings(mlx_t *mlx, t_string *old_str, t_game *game)
{
	free(game->mov_arr);
	free(game->rem_c_arr);
	mlx_delete_image(mlx, old_str->score);
	mlx_delete_image(mlx, old_str->score_point);
	mlx_delete_image(mlx, old_str->num_col);
	mlx_delete_image(mlx, old_str->remain_col);
}

void	bool_free(bool **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
	arr = NULL;
}

void	free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}
