/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:34:43 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 16:57:17 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	if_forest(t_game *g, int y, int x)
{
	if (g->map->matrix[y][x] == '1')
		put_wall(g, y + 1, x + 1);
	else if (g->map->matrix[y][x] == '0')
		put_tiles(g, y + 1, x + 1);
	else if (g->map->matrix[y][x] == 'P')
		put_charac(g, y + 1, x + 1);
	else if (g->map->matrix[y][x] == 'E')
		put_escape(g, y + 1, x + 1);
	else if (g->map->matrix[y][x] == 'C')
		put_collects(g, y + 1, x + 1);
}

void	ft_put_image(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
			if_forest(g, y, x);
	}
}
