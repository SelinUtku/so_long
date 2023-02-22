/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:10:23 by sutku             #+#    #+#             */
/*   Updated: 2023/02/22 20:34:43 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_image(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_message(OPEN_IMAGE);
	close(fd);
}

mlx_image_t	*put_image_to_map(mlx_t *mlx, char *path)
{
	xpm_t			*xpm;
	mlx_image_t		*img;

	open_image(path);
	xpm = mlx_load_xpm42(path);
	if (!xpm)
		error_message(LOAD_XPM);
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error_message(MLX_TEXTURE);
	mlx_delete_xpm42(xpm);
	return (img);
}

void	put_assets_to_images(mlx_t *mlx, t_images *img, t_game *game)
{
	img->bg_img = put_image_to_map(mlx, "./img/background.xpm42");
	if (!img->bg_img)
		error_message(MLX_TEXTURE);
	game->p_img = put_image_to_map(mlx, "./img/fox.xpm42");
	if (!game->p_img)
		error_message(MLX_TEXTURE);
	img->w_img = put_image_to_map(mlx, "./img/wall.xpm42");
	if (!img->w_img)
		error_message(MLX_TEXTURE);
	img->c_img = put_image_to_map(mlx, "./img/col.xpm42");
	if (!img->c_img)
		error_message(MLX_TEXTURE);
	img->d_img = put_image_to_map(mlx, "./img/door.xpm42");
	if (!img->d_img)
		error_message(MLX_TEXTURE);
}

void	put_assets_to_map(mlx_t *mlx, t_game *game, t_images *img)
{
	int				i;
	int				j;

	i = -1;
	if (mlx_image_to_window(mlx, img->bg_img, 0, 0) < 0)
		error_message(MLX_IMG_WND);
	img->score = mlx_put_string(mlx, "SCORE : ", 10, (game->height) * 80 + 10);
	img->num_col = mlx_put_string(mlx, "#OF_RADISH : ",10, (game->height) * 80 + 40);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map_arr[i][j] == 'P')
				if (mlx_image_to_window(mlx, game->p_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == 'C')
				if (mlx_image_to_window(mlx, img->c_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == 'E')
				if (mlx_image_to_window(mlx, img->d_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == '1')
				if (mlx_image_to_window(mlx, img->w_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
		}
	}
	game->imgs = img;
}
