/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:19:10 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/07 15:12:51 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	deal_key(int key, t_game *game)
{
	if (key == XK_Escape)
		clear_game(game);
	else if (key == XK_d || key == XK_Right)
		move_right(game);
	else if (key == XK_a || key == XK_Left)
		move_left(game);
	else if (key == XK_w || key == XK_Up)
		move_up(game);
	else if (key == XK_s || key == XK_Down)
		move_down(game);
	return (0);
}

static int	destroy_notif(t_game *game)
{
	clear_game(game);
	return (0);
}

void	open_window(t_game *game)
{
	int		w;
	int		h;
	t_mlx	*mlx2;

	game->mlx = malloc(sizeof(t_mlx));
	mlx2 = game->mlx;
	w = (game->map->x + 2) * 64;
	h = (game->map->y + 2) * 64;
	mlx2->mlx_ptr = mlx_init();
	if (mlx2->mlx_ptr == NULL)
		ft_error(12, game);
	mlx2->win_ptr = mlx_new_window(mlx2->mlx_ptr, w, h, "TIG Simulator");
	if (mlx2->win_ptr == NULL)
		ft_error(13, game);
	ft_import_images(game);
	print_image(game);
	mlx_key_hook(mlx2->win_ptr, deal_key, game);
	mlx_hook(mlx2->win_ptr, DestroyNotify, 0, destroy_notif, game);
	mlx_loop_hook(mlx2->mlx_ptr, wall_animation, game);
	mlx_loop(mlx2->mlx_ptr);
}
