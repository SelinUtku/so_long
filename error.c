/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:05:55 by sutku             #+#    #+#             */
/*   Updated: 2023/02/22 20:13:49 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i] != '\0')
			i++;
		write(2, ptr, i);
		exit(-1);
	}
	write(2, "Error\n", 6);
	exit(-1);
}

void	check_map(t_game *game)
{
	check_map_assets(game);
	check_num_assets(game);
	check_valid_path(game);
	check_collectable(game);
}

void	check_map_assets(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((i == 0 || i == game->height - 1) && game->map_arr[i][j] != '1')
				error_message(W_ERROR);
			if ((j == 0 || j == game->width - 1) && game->map_arr[i][j] != '1')
				error_message(W_ERROR);
			else
				if ((game->map_arr[i][j] != '0') && (game->map_arr[i][j] != 'C')
				&& (game-> map_arr[i][j] != '1') && (game->map_arr[i][j] != 'E')
				&& (game->map_arr[i][j] != 'X') && (game->map_arr[i][j] != 'P'))
					error_message(I_MAP);
			j++;
		}
		i++;
	}
}

void	check_num_assets(t_game *game)
{
	if (game->collectable < 1)
		error_message(C_ERROR);
	if (game->e_xit != 1)
		error_message(EXIT_E);
	if (game -> player != 1)
		error_message(P_ERROR);
	if (game->enemy != 1)
		error_message(E_ERROR);
}