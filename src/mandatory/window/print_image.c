/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:34:43 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/16 14:26:36 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	if_forest(t_game *g, int y, int x)
{
	char	c;

	c = g->map->matrix[y][x];
	if (c == '1')
		put_wall(g, y + 1, x + 1);
	else if (c == '0')
		put_tiles(g, y + 1, x + 1);
	else if (c == 'P')
		put_charac(g, y + 1, x + 1);
	else if (c == 'E')
		put_escape(g, y + 1, x + 1);
	else if (c == 'C')
		put_collects(g, y + 1, x + 1);
}

void	print_image(t_game *g)
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
