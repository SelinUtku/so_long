/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:10:23 by sutku             #+#    #+#             */
/*   Updated: 2023/03/17 19:08:32 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*put_image_to_map(t_game *game, char *path)
{
	xpm_t			*xpm;
	mlx_image_t		*img;

	open_image(path, game);
	xpm = mlx_load_xpm42(path);
	if (!xpm)
		error_message(LOAD_XPM, game);
	img = mlx_texture_to_image(game->mlx, &xpm->texture);
	if (!img)
		error_message(MLX_TEXTURE, game);
	mlx_delete_xpm42(xpm);
	return (img);
}

void	put_assets_to_images(t_images *img, t_game *game)
{
	if (game->imgs != NULL)
	{	
		game->old_images = game->imgs;
		delete_images(game->mlx, game->old_images);
		game->old_images = NULL;
	}
	img->bg_img = put_image_to_map(game, "./img/background.xpm42");
	img->p_down = put_image_to_map(game, "./img/fox.xpm42");
	img->p_up = put_image_to_map(game, "./img/fox_up.xpm42");
	img->p_right = put_image_to_map(game, "./img/fox_right.xpm42");
	img->p_left = put_image_to_map(game, "./img/fox_left.xpm42");
	img->w_img = put_image_to_map(game, "./img/wall.xpm42");
	img->c_img = put_image_to_map(game, "./img/col.xpm42");
	img->d_img = put_image_to_map(game, "./img/door.xpm42");
	img->ruby_img = put_image_to_map(game, "./img/ruby.xpm42");
	img->s_rip_img = put_image_to_map(game, "./img/s_rip.xpm42");
	img->b_rip_img = put_image_to_map(game, "./img/b_rip.xpm42");
	img->s_win_img = put_image_to_map(game, "./img/s_win.xpm42");
	img->b_win_img = put_image_to_map(game, "./img/b_win.xpm42");
	img->en_one_img = put_image_to_map(game, "./img/bomb2.xpm42");
	img->en_two_img = put_image_to_map(game, "./img/bomb1.xpm42");
	put_assets_to_map(game, img);
}

void	other_img(t_game *game, t_images *img, int i, int j)
{
	if (mlx_image_to_window(game->mlx, img->bg_img, j * 80, i * 80) < 0)
		error_message(MLX_IMG_WND, game);
	if (game->map_arr[i][j] == 'C' && game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->c_img, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	if (game->map_arr[i][j] == '1' && game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->w_img, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	if (game->map_arr[i][j] == 'E' && game->col == 0 &&
			game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->ruby_img, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	if (game->map_arr[i][j] == 'E' && game->col != 0 &&
			game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->d_img, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	if (game->map_arr[i][j] == 'X' && game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->en_one_img, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
}

void	ply_all_images(t_game *game, t_images *img, int i, int j)
{
	other_img(game, img, i, j);
	if (game->drc == 0 && game->map_arr[i][j] == 'P' && game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->p_down, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	if (game->drc == 1 && game->map_arr[i][j] == 'P' && game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->p_up, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	if (game->drc == 2 && game->map_arr[i][j] == 'P' && game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->p_left, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
	if (game->drc == 3 && game->map_arr[i][j] == 'P' && game->game_state == 0)
		if (mlx_image_to_window(game->mlx, img->p_right, j * 80, i * 80) < 0)
			error_message(MLX_IMG_WND, game);
}

void	put_assets_to_map(t_game *game, t_images *img)
{
	int	i;
	int	j;

	if (game->game_state == -1)
	{
		rip_img(game);
		return ;
	}
	if (game->game_state == 1)
	{
		win_img(game, game->imgs);
		return ;
	}
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			ply_all_images(game, img, i, j);
	}
	game->imgs = img;
}
