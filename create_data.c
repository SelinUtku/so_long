/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:26:41 by sutku             #+#    #+#             */
/*   Updated: 2023/02/22 19:48:25 by sutku            ###   ########.fr       */
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
}

// void	close_images(void)
// {
// 	mlx_delete_image(mlx, img->bg_img);
// 	mlx_delete_image(mlx, img->d_img);
// 	mlx_delete_image(mlx, img->w_img);
// }