/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:37:10 by sutku             #+#    #+#             */
/*   Updated: 2023/02/18 16:58:30 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	measure_map(t_map *map, char *path)
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
	map->height = count;
	map->width = i;
	close(fd);
}

void	put_map_to_arr(t_map *map, t_player *p, char *path)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	map->map_arr = malloc((map-> height * sizeof(char *)) + 1);
	map->map_arr[i] = get_next_line(fd);
	while (map-> map_arr[i] != NULL)
	{
		i++;
		map->map_arr[i] = get_next_line(fd);
	}
	close(fd);
}

void	read_map(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map-> map_arr[i][j] == 'C')
				map->collectable++;
			else if (map-> map_arr[i][j] == 'P')
			{
				player->cur[0] = i;
				player->cur[1] = j;
				map-> player++;
			}
			else if (map-> map_arr[i][j] == 'E')
			{
				map->exit_idx[0] = i;
				map->exit_idx[1] = j;
				map->e_xit++;
			}
			else if (map-> map_arr[i][j] == 'K')
				map-> enemy++;
		}
	}
}
