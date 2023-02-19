/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:07:57 by sutku             #+#    #+#             */
/*   Updated: 2023/02/18 17:33:43 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	**dfs_visited(t_map *map, t_player *player)
{
	bool	**visited;
	int		i;
	int		j;

	i = 0;
	visited = malloc(map->height * (sizeof(bool *)));
	while (i < map-> height)
	{
		j = 0;
		visited[i] = malloc(map->width * sizeof(bool));
		while (j < map-> width)
		{
			visited[i][j] = false;
			j++;
		}
		i++;
	}
	return (visited);
}

bool	dfs_c(t_map *map, int i, int j, bool **visit)
{
	if (visit[i][j] || map->map_arr[i][j] == '1')
		return (false);
	if (i == map->col_index[0] && j == map->col_index[1])
		return (true);
	visit[i][j] = true;
	if (dfs_c(map, i - 1, j, visit))//up
		return (true);
	if (dfs_c(map, i + 1, j, visit))//down
		return (true);
	if (dfs_c(map, i , j - 1, visit))//left
		return (true);
	if (dfs_c(map, i, j + 1, visit))//right
		return (true);
	return (false);
}

void	check_collectable(t_map *map, t_player *player)
{
	int		i;
	int		j;
	bool	**visited;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_arr[i][j] == 'C')
			{
				visited = dfs_visited(map, player);
				map->col_index[0] = i;
				map->col_index[1] = j;
				if (!dfs_c(map, player->cur[0], player->cur[1], visited))
					error_message(UN_COL);
			}
		}
	}
}

bool	dfs_e(t_map *map, int i, int j, bool **visit)
{
	if (visit[i][j] || map->map_arr[i][j] == '1')
		return (false);
	if (i == map->exit_idx[0] && j == map->exit_idx[1])
		return (true);
	visit[i][j] = true;
	if (dfs_e(map, i - 1, j, visit))//up
		return (true);
	if (dfs_e(map, i + 1, j, visit))//down
		return (true);
	if (dfs_e(map, i , j - 1, visit))//left
		return (true);
	if (dfs_e(map, i, j + 1, visit))//right
		return (true);
	return (false);
}

void	check_valid_path(t_map *map, t_player *player)
{
	bool	**visited;

	visited = dfs_visited(map, player);
	if (!dfs_e(map, player->cur[0], player->cur[1], visited))
		error_message(NO_PATH);
}
