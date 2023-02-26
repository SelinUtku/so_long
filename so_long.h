/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:17:16 by sutku             #+#    #+#             */
/*   Updated: 2023/02/26 18:14:40 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include  "/Users/sutku/Projects/so_long/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <unistd.h>
# include "ftprintf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# define W_ERROR "Invalid map ! Not Surronded with walls."
# define I_MAP "Invalid map ! There is/are another character"
# define C_ERROR "There is no Collectable in the map"
# define EXIT_E "There is no Exit in the map"
# define P_ERROR "Player number is not 1"
# define E_ERROR "Enemy number is not 1"
# define SQ_ERROR "The map is not square"
# define NO_PATH "Unreachable Exit"
# define UN_COL "At least one unreachable collectable"
# define OPEN_IMAGE "Image couldn't open !"
# define LOAD_XPM "Loading Xpm.42 Error"
# define MLX_TEXTURE "Texture to image Error"
# define MLX_IMG_WND "Image to window Error"
# define ARGC_ERROR "Number of argc is wrong"

typedef struct s_images
{
	mlx_image_t	*p_down;
	mlx_image_t	*p_left;
	mlx_image_t	*p_right;
	mlx_image_t	*p_up;
	mlx_image_t	*rip_img;
	mlx_image_t	*c_img;
	mlx_image_t	*ruby_img;
	mlx_image_t	*d_img;
	mlx_image_t	*w_img;
	mlx_image_t	*bg_img;
	mlx_image_t	*win_img;
	mlx_image_t	*en_one_img;
	mlx_image_t	*en_two_img;
}t_images;

typedef struct s_string
{
	mlx_image_t	*score;
	mlx_image_t	*score_point;
	mlx_image_t	*num_col;
	mlx_image_t	*remain_col;
}t_string;

typedef struct s_game
{
	int			collectable;
	int			player;
	int			enemy;
	int			en_idx[2];
	int			e_xit;
	int			exit_idx[2];
	int			width;
	int			height;
	int			col_index[2];
	char		**map_arr;
	int			p_cur[2];
	int			p_num_mov;
	char		*mov_arr;
	char		*rem_c_arr;
	int			exist_msg;
	int			game_state;
	mlx_t		*mlx;
	mlx_image_t	*msg;
	mlx_image_t	*old_player;
	t_images	*imgs;
	t_images	*old_images;
	t_string	*str;
	t_string	*old_str;
	int			drc;
}t_game;

void			open_image(char *str);
void			error_message(char *ptr);
void			measure_map(t_game *game, char *path);
void			read_map(t_game *game);
void			create_data(t_game *game);
void			put_map_to_arr(t_game *game, char *path);
void			check_map_assets(t_game *game);
void			check_num_assets(t_game *game);
void			check_map(t_game *game);
void			check_valid_path(t_game *game);
bool			**dfs_visited(t_game *game);
bool			dfs_e(t_game *game, int i, int j, bool **visit);
bool			dfs_c(t_game *game, int i, int j, bool **visit);
void			check_collectable(t_game *game);
mlx_image_t		*put_image_to_map(mlx_t *mlx, char *path);
void			put_assets_to_map(mlx_t *mlx, t_game *game, t_images *img);
void			put_assets_to_images(mlx_t *mlx, t_images *img, t_game *game);
void			my_hook(mlx_key_data_t k_data, void *param);
void			delete_images(mlx_t *mlx, t_images *img);
void			string_to_map(t_game *game, t_string *str);
void			delete_strings(mlx_t *mlx, t_string *old_str);
void			move_up(t_game *game, int i, int j);
void			move_down(t_game *game, int i, int j);
void			move_left(t_game *game, int i, int j);
void			move_right(t_game *game, int i, int j);

#endif