/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:10:23 by sutku             #+#    #+#             */
/*   Updated: 2023/02/26 07:34:35 by sutku            ###   ########.fr       */
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
	{
		game->old_images = game->imgs;
		delete_images(game->mlx, game->old_images);
	}
	img->bg_img = put_image_to_map(mlx, "./img/background.xpm42");
	if (!img->bg_img)
		error_message(MLX_TEXTURE);
	img->p_img = put_image_to_map(mlx, "./img/fox.xpm42");
	if (!img->p_img)
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
	img->ruby_img = put_image_to_map(mlx, "./img/ruby.xpm42");
	if (!img->ruby_img)
		error_message(MLX_TEXTURE);
	img->rip_img = put_image_to_map(mlx, "./img/rip.xpm42");
	if (!img->rip_img)
		error_message(MLX_TEXTURE);
	img->win_img = put_image_to_map(mlx, "./img/win.xpm42");
	if (!img->win_img)
		error_message(MLX_TEXTURE);
	img->en_one_img = put_image_to_map(mlx, "./img/en1.xpm42");
	if (!img->en_one_img)
		error_message(MLX_TEXTURE);
	// img->en_two_img = put_image_to_map(mlx, "./img/en2.xpm42");
	// if (!img->en_two_img)
	// 	error_message(MLX_TEXTURE);
	put_assets_to_map(game->mlx, game, img);
}

void	put_assets_to_map(mlx_t *mlx, t_game *game, t_images *img)
{
	int				i;
	int				j;

	i = -1;
	if (game->game_state == -1)
	{
		if (mlx_image_to_window(game -> mlx, game->imgs->rip_img, 500, 100) < 0)
			error_message(MLX_IMG_WND);
		return ;
	}
	if(game->game_state == 1)
	{
		if (mlx_image_to_window(game -> mlx, game->imgs->win_img, 500, 100) < 0)
			error_message(MLX_IMG_WND);
		return ;
	}
	if (mlx_image_to_window(mlx, img->bg_img, 0, 0) < 0)
		error_message(MLX_IMG_WND);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map_arr[i][j] == 'P' && game->game_state == 0)
				if (mlx_image_to_window(mlx, img->p_img, j * 80 , i * 80) < 0)
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
				if (mlx_image_to_window(mlx, img->en_one_img, j * 80 , i * 80) < 0)
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
	mlx_delete_image(mlx, img->p_img);
	mlx_delete_image(mlx, img->win_img);
	mlx_delete_image(mlx, img->rip_img);
	mlx_delete_image(mlx, img->en_one_img);
	// mlx_delete_image(mlx, img->en_two_img);
}

void	enemy_sprit(mlx_t *mlx, t_game *game)
{

	
}