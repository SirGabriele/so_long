/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:51:33 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/02 15:04:08 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_patrol(t_game *g, int y, int x)
{
	if (g->map->matrix[y - 2][x - 1] == '0')
	{
		ft_put(g->mlx, g->patrol[1].img, x * 64, (y - 1) * 64);
		g->map->matrix[y - 2][x - 1] = 'L';
	}
	else if (g->map->matrix[y][x - 1] == '0')
	{
		ft_put(g->mlx, g->patrol[3].img, x * 64, (y + 1) * 64);
		g->map->matrix[y][x - 1] = 'L';
	}
	else if (g->map->matrix[y - 1][x - 2] == '0')
	{
		ft_put(g->mlx, g->patrol[0].img, (x - 1) * 64, y * 64);
		g->map->matrix[y - 1][x - 2] = 'L';
	}
	else if (g->map->matrix[y - 1][x] == '0')
	{
		ft_put(g->mlx, g->patrol[2].img, (x + 1) * 64, y * 64);
		g->map->matrix[y - 1][x] = 'L';	
	}
}
