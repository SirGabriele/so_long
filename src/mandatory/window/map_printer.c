/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:32:49 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 15:44:16 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_collects(t_game *g, int y, int x)
{
	t_mlx	*m;
	t_img	*c;
	int		x2;
	int		y2;

	m = g->mlx;
	c = g->col;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, c[0].img, x2, y2);
}

void	put_escape(t_game *g, int y, int x)
{
	t_mlx	*m;
	t_img	*e;
	int		x2;
	int		y2;

	m = g->mlx;
	e = g->esc;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, e[1].img, x2, y2);
	g->map->esc_x = x;
	g->map->esc_y = y;
}

void	put_charac(t_game *g, int y, int x)
{
	t_mlx	*m;
	t_img	*p;
	int		x2;
	int		y2;

	m = g->mlx;
	p = g->player_img;
	x2 = x * 64;
	y2 = y * 64;
	g->player = malloc(sizeof(t_player));
	g->player->x = x;
	g->player->y = y;
	g->player->steps = 0;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, p[1].img, x2, y2);
}

void	put_tiles(t_game *g, int y, int x)
{
	t_mlx	*m;
	t_img	*t;
	int		x2;
	int		y2;

	m = g->mlx;
	t = g->tiles;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, t[0].img, x2, y2);
}

void	put_wall(t_game *g, int y, int x)
{
	t_mlx	*m;
	t_img	*w;
	int		x2;
	int		y2;

	m = g->mlx;
	w = g->walls;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, w[0].img, x2, y2);
}	
