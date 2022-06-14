/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:38:15 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/02 18:35:01 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	can_player_move(t_game *g, int dest_x, int dest_y)
{
	if (g->map->matrix[dest_y][dest_x] == '1')
		return (1);
	if (g->map->matrix[dest_y][dest_x] == 'C')
		return ('C');
	if (g->map->matrix[dest_y][dest_x] == 'E')
		return ('E');
	if (g->map->matrix[dest_y][dest_x] == 'F')
		clear_game(g);
	return (0);
}

void	move_player_right(t_game *g, int x, int y)
{
	t_img	*r;
	t_mlx	*m;
	t_img	*t;
	int		res;

	t = g->tiles;
	m = g->mlx;
	r = g->player_img;
	res = can_player_move(g, x, y - 1);
	if (res != 1)
	{
		display_steps(g, ++(g->player->steps));
		movement_processing(g, res, x, y - 1);
		if (g->map->matrix[y - 1][x - 1] == 'E')
			ft_put(m, g->esc[0].img, (x++) * 64, y * 64);
		else
			ft_put(m, t[0].img, (x++) * 64, y * 64);
		ft_put(m, r[2].img, x * 64, y * 64);
		g->player->x = x;
	}
	else
		ft_put(m, r[2].img, x * 64, y * 64);
}

void	move_player_left(t_game *g, int x, int y)
{
	t_img	*l;
	t_mlx	*m;
	t_img	*t;
	int		res;

	t = g->tiles;
	m = g->mlx;
	l = g->player_img;
	res = can_player_move(g, x - 2, y - 1);
	if (res != 1)
	{
		display_steps(g, ++(g->player->steps));
		movement_processing(g, res, x - 2, y - 1);
		if (g->map->matrix[y - 1][x - 1] == 'E')
			ft_put(m, g->esc[0].img, (x--) * 64, y * 64);
		else
			ft_put(m, t[0].img, (x--) * 64, y * 64);
		ft_put(m, l[0].img, x * 64, y * 64);
		g->player->x = x;
	}
	else
		ft_put(m, l[0].img, x * 64, y * 64);
}

void	move_player_up(t_game *g, int x, int y)
{
	t_img	*u;
	t_mlx	*m;
	t_img	*t;
	int		res;

	t = g->tiles;
	m = g->mlx;
	u = g->player_img;
	res = can_player_move(g, x - 1, y - 2);
	if (res != 1)
	{
		display_steps(g, ++(g->player->steps));
		movement_processing(g, res, x - 1, y - 2);
		if (g->map->matrix[y - 1][x - 1] == 'E')
			ft_put(m, g->esc[0].img, x * 64, (y--) * 64);
		else
			ft_put(m, t[0].img, x * 64, (y--) * 64);
		ft_put(m, u[1].img, x * 64, y * 64);
		g->player->y = y;
	}
	else
		ft_put(m, u[1].img, x * 64, y * 64);
}

void	move_player_down(t_game *g, int x, int y)
{
	t_img	*d;
	t_mlx	*m;
	t_img	*t;
	int		res;

	t = g->tiles;
	m = g->mlx;
	d = g->player_img;
	res = can_player_move(g, x - 1, y);
	if (res != 1)
	{
		display_steps(g, ++(g->player->steps));
		movement_processing(g, res, x - 1, y);
		if (g->map->matrix[y - 1][x - 1] == 'E')
			ft_put(m, g->esc[0].img, x * 64, (y++) * 64);
		else
			ft_put(m, t[0].img, x * 64, (y++) * 64);
		ft_put(m, d[3].img, x * 64, y * 64);
		g->player->y = y;
	}
	else
		ft_put(m, d[3].img, x * 64, y * 64);
}
