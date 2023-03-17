/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:05:55 by sutku             #+#    #+#             */
/*   Updated: 2023/03/16 22:59:46 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message(char *ptr, t_game *game)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i] != '\0')
			i++;
		if (game->map_arr)
			free_map(game->map_arr);
		write(2, ptr, i);
		exit(EXIT_FAILURE);
	}
	if (game->map_arr)
		free_map(game->map_arr);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
				error_message(W_ERROR, game);
			if ((j == 0 || j == game->width - 1) && game->map_arr[i][j] != '1')
				error_message(W_ERROR, game);
			else
				if ((game->map_arr[i][j] != '0') && (game->map_arr[i][j] != 'C')
				&& (game-> map_arr[i][j] != '1') && (game->map_arr[i][j] != 'E')
				&& (game->map_arr[i][j] != 'X') && (game->map_arr[i][j] != 'P'))
					error_message(I_MAP, game);
			j++;
		}
		i++;
	}
}

void	check_num_assets(t_game *game)
{
	if (game->col < 1)
		error_message(C_ERROR, game);
	if (game->e_xit != 1)
		error_message(EXIT_E, game);
	if (game -> player != 1)
		error_message(P_ERROR, game);
	if (game->enemy != 1)
		error_message(E_ERROR, game);
}
