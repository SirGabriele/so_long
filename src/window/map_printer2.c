/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:30:46 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/07 15:42:57 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_patrol(t_game *g, int y, int x, char c)
{
	t_mlx	*m;
	t_img	*p;
	int		x2;
	int		y2;

	m = g->mlx;
	p = g->patrol_img;
	x2 = x * 64;
	y2 = y * 64;
	g->patrol = malloc(sizeof(t_patrol));
	g->patrol->x = x;
	g->patrol->y = y;
	if (c == 'U')
		ft_put(m, p[1].img, x2, y2);
	else if (c == 'D')
		ft_put(m, p[3].img, x2, y2);
	else if (c == 'L')
		ft_put(m, p[0].img, x2, y2);
	else if (c == 'R')
		ft_put(m, p[2].img, x2, y2);
	g->map->matrix[y - 1][x - 1] = 'F';
}
