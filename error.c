/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:05:55 by sutku             #+#    #+#             */
/*   Updated: 2023/02/18 15:42:52 by sutku            ###   ########.fr       */
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

void	check_map(t_map *map, t_player *player)
{
	check_map_assets(map);
	check_num_assets(map);
	check_valid_path(map, player);
	check_collectable(map, player);
}

void	check_map_assets(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == map->height - 1) && map->map_arr[i][j] != '1')
				error_message(W_ERROR);
			if ((j == 0 || j == map->width - 1) && map->map_arr[i][j] != '1')
				error_message(W_ERROR);
			else
				if ((map->map_arr[i][j] != '0') && (map->map_arr[i][j] != 'C')
				&& (map-> map_arr[i][j] != '1') && (map->map_arr[i][j] != 'E')
				&& (map->map_arr[i][j] != 'K') && (map->map_arr[i][j] != 'P'))
					error_message(I_MAP);
			j++;
		}
		i++;
	}
}

void	check_num_assets(t_map *map)
{
	if (map->collectable < 1)
		error_message(C_ERROR);
	if (map->e_xit != 1)
		error_message(EXIT_E);
	if (map -> player != 1)
		error_message(P_ERROR);
	if (map->enemy != 1)
		error_message(E_ERROR);
}