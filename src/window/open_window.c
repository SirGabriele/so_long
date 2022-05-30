/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:19:10 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 14:33:28 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	deal_key(int key, t_game *game)
{
	ft_printf("key = %c // code = %d\n", key, key);	
	if (key == XK_Escape)
		clear_game(game);
	return (0);
}

static int	destroy_notif(t_game *game)
{
	clear_game(game);
	return (0);
}

void	open_window(t_game *game)
{
	int		width;
	int		height;
	t_mlx	*mlx2;

	game->mlx = malloc(sizeof(t_mlx));
	mlx2 = game->mlx;
	width = (game->map->x + 2) * 64;
	height = (game->map->y + 2) * 64;
	mlx2->mlx_ptr = mlx_init();
	if (mlx2->mlx_ptr == NULL)
		ft_error(12, game);
	mlx2->win_ptr = mlx_new_window(mlx2->mlx_ptr, width, height, "so_long");
	if (mlx2->win_ptr == NULL)
		ft_error(13, game);
	ft_import_images(game);
	ft_put_image(game);
	mlx_key_hook(mlx2->win_ptr, deal_key, game);
	mlx_hook(mlx2->win_ptr, DestroyNotify, 0, destroy_notif, game);
	mlx_loop(mlx2->mlx_ptr);
}
