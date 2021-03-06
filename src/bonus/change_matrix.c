/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:16:50 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/07 15:45:13 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_patrol(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
		{
			if (g->map->matrix[y][x] == 'E')
			{
				if (g->map->matrix[y - 1][x] == '0')
					g->map->matrix[y - 1][x] = 'U';
				else if (g->map->matrix[y + 1][x] == '0')
					g->map->matrix[y + 1][x] = 'D';
				else if (g->map->matrix[y][x - 1] == '0')
					g->map->matrix[y][x - 1] = 'L';
				else if (g->map->matrix[y][x + 1] == '0')
					g->map->matrix[y][x + 1] = 'R';
				else
					ft_error(26, g);
			}
		}
	}
}

void	change_matrix(t_game *g)
{
	int	y;
	int	x;
	int	count_p;
	int	count_e;
	int	random[2];

	srand(time(NULL));
	random[0] = (int)(rand() / (double)RAND_MAX * (g->map->nb_starts - 1));
	random[1] = (int)(rand() / (double)RAND_MAX * (g->map->nb_esc - 1));
	y = -1;
	count_p = 0;
	count_e = 0;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
		{
			if (g->map->matrix[y][x] == 'P' && count_p++ != random[0])
				g->map->matrix[y][x] = '0';
			else if (g->map->matrix[y][x] == 'E' && count_e++ != random[1])
				g->map->matrix[y][x] = '0';
		}
	}
	add_patrol(g);
}
