/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_movement_processing.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:50:58 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/08 16:55:49 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_tile_new_pos(t_game *g)
{
	t_mlx *m;
	int		y;
	int		x;

	m = g->mlx;
	y = g->patrol->y;
	x = g->patrol->x;
	if (g->patrol->steps == 0)
	{
		g->map->matrix[y - 1][x - 1] = '0';
		ft_put(m, g->esc[0].img, (x--) * 64, y * 64);
		ft_put(m, g->patrol_img[0].img, x * 64, y * 64);
		g->map->matrix[y - 1][x - 1] = 'F';
	}
	else if (g->patrol->steps == 1)
	{
		g->map->matrix[y - 1][x - 1] = '0';
		ft_put(m, g->esc[1].img, x * 64, (y--) * 64);
		ft_put(m, g->patrol_img[1].img, x * 64, y * 64);
		g->map->matrix[y - 1][x - 1] = 'F';
	}
	else if (g->patrol->steps == 2)
	{
		g->map->matrix[y - 1][x - 1] = '0';
		ft_put(m, g->esc[2].img, (x++) * 64, y * 64);
		ft_put(m, g->patrol_img[3].img, x * 64, y * 64);
		g->map->matrix[y - 1][x - 1] = 'F';
	}
	else if (g->patrol->steps == 3)
	{
		g->map->matrix[y - 1][x - 1] = '0';
		ft_put(m, g->esc[3].img, x * 64, (y++) * 64);
		ft_put(m, g->patrol_img[3].img, x * 64, y * 64);
		g->map->matrix[y - 1][x - 1] = 'F';
	}
}
//ICI CA MERDEAFJLSDPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:KNDFOKB PKSFB DXJL B KL
//
////ICI CA M//ICI CA MERDEAFJLSDPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:KNDFOKB PKSFB DXJL B KLERDEAFJLSD//ICI CA MERDEAFJLSDPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:KNDFOKB PKSFB DXJL B KLPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:K//ICI CA MERDEAFJLSDPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:KNDFOKB PKSFB DXJL B KLNDFOKB PKSFB DXJL B KL
//
////ICI CA//ICI CA MERDEAFJLSDPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:KNDFOKB PKSFB DXJL B KL MERDEAFJLSDPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:KNDFOKB PKSFB DXJL B KL
//
////ICI CA MERDEAFJLSDPGOBN{SDGOMBPSBODNP:KBF {SFLB<\B:KNDFOKB PKSFB DXJL B KL
void	put_tile_old_pos(t_game *g)
{
	t_mlx *m;
	int		y;
	int		x;

	m = g->mlx;
	y = g->patrol->y;
	x = g->patrol->x;
	ft_put(m, g->esc[g->patrol->steps].img, x * 64, y * 64);
	if (g->patrol->steps == 0)
		g->map->matrix[y - 1][x] = '0';
	else if (g->patrol->steps == 1)
		g->map->matrix[y][x - 1] = '0';
	else if (g->patrol->steps == 2)
		g->map->matrix[y - 1][x - 2] = '0';
	else if (g->patrol->steps == 3)
		g->map->matrix[y - 2][x - 1] = '0';
}
