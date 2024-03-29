/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:26:41 by sutku             #+#    #+#             */
/*   Updated: 2023/03/14 21:20:44 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_data(t_game *game)
{
	game->collectable = 0;
	game->player = 0;
	game->e_xit = 0;
	game->width = 0;
	game->height = 0;
	game->map_arr = NULL;
	game->p_num_mov = 0;
	game->game_state = 0;
	game->drc = 0;
	game->imgs = NULL;
	game->old_images = NULL;
}

void	bool_free(bool **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
	arr = NULL;
}

void	free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}
