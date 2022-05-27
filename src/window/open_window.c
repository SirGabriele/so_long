/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:19:10 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/27 15:51:30 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	deal_key(int key, t_game *game)
{
	t_mlx	*mlx2;

	mlx2 = game->mlx;
	ft_printf("key = %c // code = %d\n", key, key);
	if (key == 65307)
	{
		mlx_clear_window(mlx2->mlx_ptr, mlx2->win_ptr);
		mlx_destroy_window(mlx2->mlx_ptr, mlx2->win_ptr);
		mlx_destroy_display(mlx2->mlx_ptr);
		clear_game(game);
	}
	return (0);
}

void	open_window(t_game *game)
{
	int		width;
	int		height;
	t_mlx	*mlx2;

	game->mlx = malloc(sizeof(t_mlx));
	mlx_init(game->mlx);
	mlx2 = game->mlx;
	width = (game->map->x + 2) * 64;
	height = (game->map->y + 2) * 64;
	mlx2->mlx_ptr = mlx_init();
	if (mlx2->mlx_ptr == NULL)
		ft_error(12, game);
	mlx2->win_ptr = mlx_new_window(mlx2->mlx_ptr, width, height, "so_long");
	if (mlx2->win_ptr == NULL)
		ft_error(13, game);
	mlx_key_hook(mlx2->win_ptr, deal_key, game);
	mlx_loop(mlx2->mlx_ptr);
}
