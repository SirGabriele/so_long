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
	int	count;
	int	random;
	
	srand(time(NULL));
	random = (int)(rand() / (double)RAND_MAX * (g->map->nb_starts - 1));
	y = -1;
	count = 0;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
		{
			if (g->map->matrix[y][x] == 'P' && count++ != random)
				g->map->matrix[y][x] = '0';
				
		}
	}
}
