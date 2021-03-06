/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:30:55 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/02 18:35:31 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_steps(t_game *g, int steps, int x, int y)
{
	int	res;

	res = 0;
	while (steps > 0)
	{
		res = steps % 10;
		ft_put(g->mlx, g->numbers[res].img, x + 25, y);
		x -= 16;
		steps /= 10;
	}
}

void	display_steps(t_game *g)
{
	int	x;

	x = g->map->x;
	g->player->steps++;
	if (g->player->steps > 2000000000)
		g->player->steps = 1;
	print_steps(g, g->player->steps, (x + 1) * 64, 25);
}
