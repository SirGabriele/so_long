/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:26:18 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/20 17:59:50 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_animation(t_game *g)
{
	static int	rate = 0;
	static int	state = 0;
	int	y;
	int	x;

	y = -1;
	if (rate == 100000)
	{
		state = state % 2;
		while (++y < g->map->y)
		{
			x = -1;
			while (++x < g->map->x)
			{
				if (g->map->matrix[y][x] == '1')
					ft_put(g->mlx, g->walls[state].img, (x + 1) * 64, (y + 1) * 64);
			}
		}
		rate = 0;
		state++;
	}
	rate++;
	return (0);
}
