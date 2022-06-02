/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:16:50 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/31 20:24:40 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_matrix(t_game *g)
{
	int	y;
	int	x;
	int	count_p;
	int	count_e;
	int	random_p;
	int	random_e;
	
	srand(time(NULL));
	random_p = (int)(rand() / (double)RAND_MAX * (g->map->nb_starts - 1));
	random_e = (int)(rand() / (double)RAND_MAX * (g->map->nb_esc - 1));
	y = -1;
	count_p = 0;
	count_e = 0;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
		{
			if (g->map->matrix[y][x] == 'P' && count_p++ != random_p)
				g->map->matrix[y][x] = '0';
			else if (g->map->matrix[y][x] == 'E' && count_e++ != random_e)
				g->map->matrix[y][x] = '0';
				
		}
	}
}
