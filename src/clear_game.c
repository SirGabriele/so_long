/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:51:44 by argomez           #+#    #+#             */
/*   Updated: 2022/05/26 13:01:38 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_mlx(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
}

static	void	clear_map(t_map *map)
{
	int	i;

	i = -1;
	free(map->name);
	if (map->matrix)
	{
		while (map->matrix[++i] != NULL)
			free(map->matrix[i]);
		free(map->matrix);
	}
	free(map->starts);
	free(map->esc);
	free(map->col);
	free(map);
}

void	clear_game(t_game *game)
{
	if (game->map != NULL)
		clear_map(game->map);
	if (game->mlx != NULL)
		clear_mlx(game->mlx);
	free(game);
	exit(0);
}
