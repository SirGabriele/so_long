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

void	change_matrix(t_game *g)
{
	int	y;
	int	x;
	int	count_p;
	int	count_e;

	y = -1;
	count_p = 1;
	count_e = 1;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
		{
			if (g->map->matrix[y][x] == 'P' && count_p++ != 1)
				g->map->matrix[y][x] = '0';
			else if (g->map->matrix[y][x] == 'E' && count_e++ != 1)
				g->map->matrix[y][x] = '0';
		}
	}
}
