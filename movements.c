/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:06:38 by sutku             #+#    #+#             */
/*   Updated: 2023/02/20 17:55:12 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	move_up(t_map *map, t_player *ply)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_arr[i][j] == 'P')
			{
				map -> map_arr[i - 1][j] = 'P';
				map -> map_arr[i][j] = '0';
				ply ->p_num_mov++;
				return ;
			}
		}
	}
}

void	my_hook(mlx_key_data_t k_data, void *param)
{
	mlx_t		*mlx;
	t_player	*ply;
	t_map		*map;

	ply = param;
	if (k_data.action == MLX_PRESS)
	{
		if (k_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(mlx);
		if (k_data.key == MLX_KEY_UP)
		{
			move_up(map, ply);
			ply->p_img->instances[0].y -=80;
		}
		if (k_data.key == MLX_KEY_DOWN)
			ply->p_img->instances[0].y +=80;
		if (k_data.key == MLX_KEY_LEFT)
			ply->p_img->instances[0].x -=80;
		if (k_data.key == MLX_KEY_RIGHT)
			ply->p_img->instances[0].x +=80;
	}	
}