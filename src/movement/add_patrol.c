/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_patrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:58:59 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/09 16:19:43 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_patrol_left(t_game *g)
{
	int	x;
	int	y;

	x = g->patrol->x;
	y = g->patrol->y;
	ft_put(g->mlx, g->esc[0].img, x * 64, y * 64);
	g->map->esc_y = y;
	g->map->esc_x = x;
	g->map->matrix[y - 1][(x--) - 1] = 'E';
	ft_put(g->mlx, g->patrol_img[0].img, x * 64, y * 64);
	g->map->matrix[y - 1][x - 1] = 'F';
	g->patrol->x = x;
//	if (g->patrol->y == g->player->y && g->patrol->x == g->player->x)
//		ft_error(30, g);
}

void	add_patrol_up(t_game *g)
{
	int	x;
	int	y;

	x = g->patrol->x;
	y = g->patrol->y;
	ft_put(g->mlx, g->esc[1].img, x * 64, y * 64);
	g->map->esc_y = y;
	g->map->esc_x = x;
	g->map->matrix[(--y) - 1][x - 1] = 'E';
	ft_put(g->mlx, g->patrol_img[1].img, x * 64, y * 64);
	g->map->matrix[y - 1][x - 1] = 'F';
	g->patrol->y = y;
//	if (g->patrol->y == g->player->y && g->patrol->x == g->player->x)
//		ft_error(30, g);
}

void	add_patrol_right(t_game *g)
{
	int	x;
	int	y;


	x = g->patrol->x;
	y = g->patrol->y;
	ft_put(g->mlx, g->esc[2].img, x * 64, y * 64);
	g->map->esc_y = y;
	g->map->esc_x = x;
	g->map->matrix[y - 1][(x++) - 1] = 'E';
	ft_put(g->mlx, g->patrol_img[2].img, x * 64, y * 64);
	g->map->matrix[y - 1][x - 1] = 'F';
	g->patrol->x = x;
//	if (g->patrol->y == g->player->y && g->patrol->x == g->player->x)
//		ft_error(30, g);
}
  
void	add_patrol_down(t_game *g)
{
	int	x;
	int	y;

	x = g->patrol->x;
	y = g->patrol->y;
	ft_put(g->mlx, g->esc[3].img, x * 64, y * 64);
	g->map->esc_y = y;
	g->map->esc_x = x;
	g->map->matrix[(y++) - 1][x - 1] = 'E';
	ft_put(g->mlx, g->patrol_img[3].img, x * 64, y * 64);
	g->map->matrix[y - 1][x - 1] = 'F';
	g->patrol->y = y;
//	if (g->patrol->y == g->player->y && g->patrol->x == g->player->x)
//		ft_error(30, g);
}
  