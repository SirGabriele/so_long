/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:47:25 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/26 18:07:29 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->matrix = NULL;
	map->nb_starts = 0;
	map->nb_esc = 0;
	map->nb_col = 0;
	map->esc_x = 0;
	map->esc_y = 0;
}
