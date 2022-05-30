/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:32:49 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 15:44:16 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_collects(t_game *game, int y, int x)
{
	t_mlx	*m;
	t_img	*c;
	int		x2;
	int		y2;

	m = game->mlx;
	c = game->collects;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, c[0].img, x2, y2);
}

void	put_escape(t_game *game, int y, int x)
{
	t_mlx	*m;
	t_img	*e;
	int		x2;
	int		y2;

	m = game->mlx;
	e = game->escapes;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, e[0].img, x2, y2);
}

void	put_charac(t_game *game, int y, int x)
{
	t_mlx	*m;
	t_img	*r;
	int		x2;
	int		y2;

	m = game->mlx;
	r = game->right;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, r[0].img, x2, y2);
}

void	put_tiles(t_game *game, int y, int x)
{
	t_mlx	*m;
	t_img	*t;
	int		x2;
	int		y2;

	m = game->mlx;
	t = game->tiles;
	x2 = x * 64;
	y2 = y * 64;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, t[0].img, x2, y2);
}

void	put_wall(t_game *game, int y, int x)
{
	t_mlx	*m;
	t_img	*w;
	int		x2;
	int		y2;

	m = game->mlx;
	w = game->walls;
	x2 = x * 64;
	y2 = y * 64;
	if (y == 1 || y == game->map->y)
		ft_put(m->mlx_ptr, m->win_ptr, w[0].img, x2, y2);
	if (x == 1 || x == game->map->x)
		ft_put(m->mlx_ptr, m->win_ptr, w[0].img, x2, y2);
}	
