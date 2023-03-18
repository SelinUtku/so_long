/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:07:57 by sutku             #+#    #+#             */
/*   Updated: 2023/03/14 21:55:04 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	**dfs_visited(t_game *game)
{
	bool	**visited;
	int		i;
	int		j;

	i = 0;
	visited = malloc(game->height * (sizeof(bool *)));
	if (!visited)
	{
		bool_free(visited, i);
		error_message(MALLOC, game);
	}
	while (i < game-> height)
	{
		j = -1;
		visited[i] = malloc(game->width * sizeof(bool));
		if (!visited[i])
		{
			bool_free(visited, i);
			error_message(MALLOC, game);
		}
		while (++j < game-> width)
			visited[i][j] = false;
		i++;
	}
	return (visited);
}

bool	dfs_c(t_game *game, int i, int j, bool **visit)
{
	if (visit[i][j] || game->map_arr[i][j] == '1' || game->map_arr[i][j] == 'E')
		return (false);
	if (i == game->col_index[0] && j == game->col_index[1])
		return (true);
	visit[i][j] = true;
	if (dfs_c(game, i - 1, j, visit))
		return (true);
	if (dfs_c(game, i + 1, j, visit))
		return (true);
	if (dfs_c(game, i, j - 1, visit))
		return (true);
	if (dfs_c(game, i, j + 1, visit))
		return (true);
	return (false);
}

void	check_collectable(t_game *game)
{
	int		i;
	int		j;
	bool	**visited;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map_arr[i][j] == 'C')
			{
				visited = dfs_visited(game);
				game->col_index[0] = i;
				game->col_index[1] = j;
				if (!dfs_c(game, game->p_cur[0], game->p_cur[1], visited))
				{
					bool_free(visited, game->height);
					error_message(UN_COL, game);
				}
				if (visited != NULL)
					bool_free(visited, game->height);
			}
		}
	}
}

bool	dfs_e(t_game *game, int i, int j, bool **visit)
{
	if (visit[i][j] || game->map_arr[i][j] == '1')
		return (false);
	if (i == game->exit_idx[0] && j == game->exit_idx[1])
		return (true);
	visit[i][j] = true;
	if (dfs_e(game, i - 1, j, visit))
		return (true);
	if (dfs_e(game, i + 1, j, visit))
		return (true);
	if (dfs_e(game, i, j - 1, visit))
		return (true);
	if (dfs_e(game, i, j + 1, visit))
		return (true);
	return (false);
}

void	check_valid_path(t_game *game)
{
	bool	**visited;

	visited = dfs_visited(game);
	if (!dfs_e(game, game->p_cur[0], game->p_cur[1], visited))
	{
		bool_free(visited, game->height);
		error_message(NO_PATH, game);
	}
	if (visited != NULL)
		bool_free(visited, game->height);
}
