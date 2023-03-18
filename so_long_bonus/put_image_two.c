/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:03:47 by sutku             #+#    #+#             */
/*   Updated: 2023/03/17 18:42:29 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_image(char *str, t_game *game)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_message(OPEN_IMAGE, game);
	close(fd);
}

void	delete_images(mlx_t *mlx, t_images *img)
{
	mlx_delete_image(mlx, img->bg_img);
	mlx_delete_image(mlx, img->c_img);
	mlx_delete_image(mlx, img->d_img);
	mlx_delete_image(mlx, img->w_img);
	mlx_delete_image(mlx, img->ruby_img);
	mlx_delete_image(mlx, img->p_down);
	mlx_delete_image(mlx, img->p_up);
	mlx_delete_image(mlx, img->p_left);
	mlx_delete_image(mlx, img->p_right);
	mlx_delete_image(mlx, img->s_win_img);
	mlx_delete_image(mlx, img->b_win_img);
	mlx_delete_image(mlx, img->s_rip_img);
	mlx_delete_image(mlx, img->b_rip_img);
	mlx_delete_image(mlx, img->en_one_img);
	mlx_delete_image(mlx, img->en_two_img);
}

void	rip_img(t_game *game)
{
	if (game->height < 5)
	{
		if (mlx_image_to_window(game->mlx, game->imgs->s_rip_img,
				game->width * 3, game->height * 3) < 0)
			error_message(MLX_IMG_WND, game);
	}
	else
		if (mlx_image_to_window(game->mlx, game->imgs->b_rip_img,
				game->width * 3, game->height * 3) < 0)
			error_message(MLX_IMG_WND, game);
}

void	win_img(t_game *game, t_images *imgs)
{
	if (game->height < 5)
	{
		if (mlx_image_to_window(game->mlx, imgs->s_win_img, game->width * 3,
				game->height * 3) < 0)
			error_message(MLX_IMG_WND, game);
	}
	else
		if (mlx_image_to_window(game->mlx, imgs->b_win_img, game->width * 3,
				game->height * 3) < 0)
			error_message(MLX_IMG_WND, game);
}
