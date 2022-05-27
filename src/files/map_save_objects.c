/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:35:30 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/27 11:48:38 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_objects(char c, int x, int y, t_map *map)
{
	static int	count_starts;
	static int	count_escapes;
	static int	count_collects;

	if (c == 'P')
	{
		map->starts[count_starts].x = x + 1;
		map->starts[count_starts].y = y + 1;
		count_starts++;
	}
	else if (c == 'E')
	{
		map->escapes[count_escapes].x = x + 1;
		map->escapes[count_escapes].y = y + 1;
		count_escapes++;
	}
	else if (c == 'C')
	{
		map->collects[count_collects].x = x + 1;
		map->collects[count_collects].y = y + 1;
		count_collects++;
	}
}

void	map_save_objects(t_map *map, t_game *game)
{
	int	y;
	int	x;

	map->starts = malloc((map->nb_starts) * sizeof(t_start));
	map->escapes = malloc((map->nb_escapes) * sizeof(t_escape));
	map->collects = malloc((map->nb_collects) * sizeof(t_collect));
	y = -1;
	while (map->matrix[++y])
	{
		x = -1;
		while (map->matrix[y][++x])
			check_objects(map->matrix[y][x], x, y, map);
	}
	(void)game;
}
