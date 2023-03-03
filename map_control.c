/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:37:10 by sutku             #+#    #+#             */
/*   Updated: 2023/03/03 15:57:44 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	measure_map(t_game *game, char *path)
{
	int		i;
	int		width;
	int		fd;
	int		count;
	char	*arr;

	width = 0;
	count = 0;
	fd = open(path, O_RDONLY);
	if (!fd)
		return ;
	arr = get_next_line(fd);
	while (arr[width] != '\n')
			width++;
	while (arr != NULL)
	{
		i = -1;
		while (arr[++i] != '\n')
			if (arr[i] == '\0')
				break ;
		if (width != i)
			error_message(SQ_ERROR);
		free(arr);
		arr = get_next_line(fd);
		count++;
	}
	game->height = count;
	game->width = i;
	close(fd);
}

void	put_map_to_arr(t_game *game, char *path)
{
	int	fd;
	int	i;
	int	j;

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

void	read_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
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
	}
}
