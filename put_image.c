/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:10:23 by sutku             #+#    #+#             */
/*   Updated: 2023/02/20 13:03:45 by sutku            ###   ########.fr       */
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

void	put_walls_to_map(t_map *map, t_images *img, mlx_t *mlx)
{
	int				i;
	int				j;

	i = -1;
	open_image("./img/wall.xpm42");
	img->wall = mlx_load_xpm42("./img/wall.xpm42");
	if (!img->wall)
		error_message(LOAD_XPM);
	img->w_img = mlx_texture_to_image(mlx, &img->wall->texture);
	if (!img->w_img)
		error_message(MLX_TEXTURE);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_arr[i][j] == '1')
			{
				if (mlx_image_to_window(mlx, img->w_img, j*80 , i*80) < 0)
					error_message(MLX_IMG_WND);
			}
		}
	}
}

void	put_bg_to_map(t_map *map, mlx_t *mlx)
{
	t_images		img;

	open_image("./img/background.xpm42");
	open_image("./img/score_board.xpm42");
	img.bg = mlx_load_xpm42("./img/background.xpm42");
	if (!img.bg)
		error_message(LOAD_XPM);
	img.bg_img = mlx_texture_to_image(mlx, &img.bg->texture);
	if (!img.bg_img)
		error_message(MLX_TEXTURE);
	if (mlx_image_to_window(mlx, img.bg_img, 0, 0) < 0)
		error_message(MLX_IMG_WND);
	put_walls_to_map(map, &img, mlx);
	img.score = mlx_put_string(mlx, "SCORE : ",10, (map->height) * 80 + 10);
	img.num_col = mlx_put_string(mlx, "#OF_RADISH : ",10, (map->height) * 80 + 40);
	put_assets_to_map(map, &img, mlx);
}

void	put_assets_to_map(t_map *map, t_images *img, mlx_t *mlx)
{
	int				i;
	int				j;

	i = -1;
	open_image("./img/col.xpm42");
	open_image("./img/door.xpm42");
	img->wall = mlx_load_xpm42("./img/col.xpm42");
	if (!img ->wall)
		error_message(LOAD_XPM);
	img->w_img = mlx_texture_to_image(mlx, &img->wall->texture);
	if (!img->w_img)
		error_message(MLX_TEXTURE);
	img->door = mlx_load_xpm42("./img/door.xpm42");
	if (!img ->door)
		error_message(LOAD_XPM);
	img->d_img = mlx_texture_to_image(mlx, &img->door->texture);
	if (!img->d_img)
		error_message(MLX_TEXTURE);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_arr[i][j] == 'C')
				if (mlx_image_to_window(mlx, img->w_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
			if (map->map_arr[i][j] == 'E')
				if (mlx_image_to_window(mlx, img->d_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
		}
	}
}

void	player_image(t_map *map, mlx_t *mlx, t_player *player)
{
	int				i;
	int				j;

	i = -1;
	open_image("./img/fox.xpm42");
	player->ply = mlx_load_xpm42("./img/fox.xpm42");
	if (!player->ply)
		error_message(LOAD_XPM);
	player->p_img = mlx_texture_to_image(mlx, &player->ply->texture);
	if (!player->p_img)
		error_message(MLX_TEXTURE);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_arr[i][j] == 'P')
				if (mlx_image_to_window(mlx, player->p_img, j * 80 , i * 80) < 0)
					error_message(MLX_IMG_WND);
		}
	}
}
