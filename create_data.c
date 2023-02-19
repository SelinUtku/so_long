/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:26:41 by sutku             #+#    #+#             */
/*   Updated: 2023/02/18 11:08:08 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_data(t_map *map, t_player *p)
{
	map-> collectable = 0;
	map-> player = 0;
	map-> enemy = 0;
	map-> e_xit = 0;
	map-> width = 0;
	map-> height = 0;
	map-> map_arr = NULL;
}
