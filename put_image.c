/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:10:23 by sutku             #+#    #+#             */
/*   Updated: 2023/03/03 20:14:43 by sutku            ###   ########.fr       */
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
	if (game->imgs != NULL)
		delete_images(game->mlx, game->imgs);
	if (game->game_state == -1)
	{
		img->rip_img = put_image_to_map(game->mlx, "./img/rip.xpm42");
		if (mlx_image_to_window(game -> mlx, game->imgs->rip_img, 500, 100) < 0)
			error_message(MLX_IMG_WND);
		return ;
	}
	img->bg_img = put_image_to_map(mlx, "./img/background.xpm42");
	img->p_down = put_image_to_map(mlx, "./img/fox.xpm42");
	img->p_up = put_image_to_map(mlx, "./img/fox_up.xpm42");
	img->p_right = put_image_to_map(mlx, "./img/fox_right.xpm42");
	img->p_left = put_image_to_map(mlx, "./img/fox_left.xpm42");
	img->w_img = put_image_to_map(mlx, "./img/wall.xpm42");
	img->c_img = put_image_to_map(mlx, "./img/col.xpm42");
	img->d_img = put_image_to_map(mlx, "./img/door.xpm42");
	img->ruby_img = put_image_to_map(mlx, "./img/ruby.xpm42");
	img->rip_img = put_image_to_map(mlx, "./img/rip.xpm42");
	img->win_img = put_image_to_map(mlx, "./img/win.xpm42");
	img->en_one_img = put_image_to_map(mlx, "./img/bomb2.xpm42");
	put_assets_to_map(game->mlx, game, img);
}

void	put_assets_to_map(mlx_t *mlx, t_game *game, t_images *img)
{
	int				i;
	int				j;

	i = -1;
	if (game->game_state == 1)
	{
		if (mlx_image_to_window(game -> mlx, game->imgs->win_img, 500, 100) < 0)
			error_message(MLX_IMG_WND);
		return ;
	}
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (mlx_image_to_window(mlx, img->bg_img, j * 80, i * 80) < 0)
				error_message(MLX_IMG_WND);
			if (game->drc == 0 && game->map_arr[i][j] == 'P' && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->p_down, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->drc == 1 && game->map_arr[i][j] == 'P' && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->p_up, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->drc == 2 && game->map_arr[i][j] == 'P' && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->p_left, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->drc == 3 && game->map_arr[i][j] == 'P' && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->p_right, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == 'C' && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->c_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == '1' && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->w_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == 'E' && game->collectable == 0 && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->ruby_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == 'E' && game->collectable != 0 && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->d_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (game->map_arr[i][j] == 'X' && game->game_state == 0)
				if (mlx_image_to_window(game->mlx, img->en_one_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
		}
	}
	game->imgs = img;
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
	if(img->rip_img)
		mlx_delete_image(mlx, img->rip_img);
	if (img->en_one_img)
		mlx_delete_image(mlx, img->en_one_img);
	if (img->en_two_img)
		mlx_delete_image(mlx, img->en_two_img);
}
