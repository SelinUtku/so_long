/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:03:47 by sutku             #+#    #+#             */
/*   Updated: 2023/03/14 18:04:58 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_delete_image(mlx, img->win_img);
}
