/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:38:05 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 13:55:06 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_up(t_game *game)
{
	t_img	*u;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->up = malloc(sizeof(t_img) * 1);
	u = game->up;
	u[0].p = "images/pacman_up.xpm";
	i = -1;
	while (++i < 1)
	{
		u[i].w = 64;
		u[i].h = 64;
		u[i].img = mlx_xpm_file_to_image(m->mlx_ptr, u[i].p, &u[i].w, &u[i].h);
	}
}

static void	init_down(t_game *game)
{
	t_img	*d;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->down = malloc(sizeof(t_img) * 1);
	d = game->down;
	d[0].p = "images/pacman_down.xpm";
	i = -1;
	while (++i < 1)
	{
		d[i].w = 64;
		d[i].h = 64;
		d[i].img = mlx_xpm_file_to_image(m->mlx_ptr, d[i].p, &d[i].w, &d[i].h);
	}
}

static void	init_left(t_game *game)
{
	t_img	*l;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->left = malloc(sizeof(t_img) * 1);
	l = game->left;
	l[0].p = "images/pacman_left.xpm";
	i = -1;
	while (++i < 1)
	{
		l[i].w = 64;
		l[i].h = 64;
		l[i].img = mlx_xpm_file_to_image(m->mlx_ptr, l[i].p, &l[i].w, &l[i].h);
	}
}

static void	init_right(t_game *game)
{
	t_img	*r;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->right = malloc(sizeof(t_img) * 1);
	r = game->right;
	r[0].p = "images/pacman_right.xpm";
	i = -1;
	while (++i < 1)
	{
		r[i].w = 64;
		r[i].h = 64;
		r[i].img = mlx_xpm_file_to_image(m->mlx_ptr, r[i].p, &r[i].w, &r[i].h);
	}
}

void	init_char(t_game *game)
{
	init_up(game);
	init_down(game);
	init_left(game);
	init_right(game);
}
