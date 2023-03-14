/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:37:10 by sutku             #+#    #+#             */
/*   Updated: 2023/03/14 18:01:02 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_square(t_tmp *tmp, t_game *game)
{
	tmp->i = -1;
	while (tmp->arr[++tmp->i] != '\n')
		if (tmp->arr[tmp->i] == '\0')
			break ;
	if (tmp->width != tmp->i)
		error_message(SQ_ERROR, game);
	free(tmp->arr);
	tmp->arr = get_next_line(tmp->fd);
	tmp->count++;
}

void	measure_map(t_game *game, char *path)
{
	t_tmp	tmp;

	tmp.width = 0;
	tmp.count = 0;
	tmp.fd = open(path, O_RDONLY);
	if (!tmp.fd)
		return ;
	tmp.arr = get_next_line(tmp.fd);
	if (tmp.arr == NULL)
		error_message(EMPTY_FILE, game);
	while (tmp.arr[tmp.width] != '\n')
		tmp.width++;
	while (tmp.arr != NULL)
		check_square(&tmp, game);
	game->height = tmp.count;
	game->width = tmp.i;
	close(tmp.fd);
}

void	put_map_to_arr(t_game *game, char *path)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	game->map_arr = malloc((game-> height + 1) * sizeof(char *));
	game->map_arr[i] = get_next_line(fd);
	while (game->map_arr && game-> map_arr[i] != NULL)
	{
		i++;
		game->map_arr[i] = get_next_line(fd);
	}
	close(fd);
}

void	init_map_assets(t_game *game, int i, int j)
{
	if (game-> map_arr[i][j] == 'C')
		game->collectable++;
	else if (game-> map_arr[i][j] == 'P')
	{
		game->p_cur[0] = i;
		game->p_cur[1] = j;
		game-> player++;
	}
	else if (game-> map_arr[i][j] == 'E')
	{
		game->exit_idx[0] = i;
		game->exit_idx[1] = j;
		game->e_xit++;
	}
	else if (game-> map_arr[i][j] == 'X')
	{
		game->en_idx[0] = i;
		game->en_idx[1] = j;
		game-> enemy++;
	}
}

void	read_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			init_map_assets(game, i, j);
	}
}
