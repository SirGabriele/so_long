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

static void	clear_entities(t_game *g)
{
	free(g->player);
	free(g->patrol);
}

static void	clear_mlx(t_game *g)
{
	mlx_clear_window(g->mlx->mlx_ptr, g->mlx->win_ptr);
	clear_images(g);
	clear_entities(g);
	mlx_destroy_window(g->mlx->mlx_ptr, g->mlx->win_ptr);
	mlx_destroy_display(g->mlx->mlx_ptr);
	free(g->mlx->mlx_ptr);
	free(g->mlx);
}

static	void	clear_map(t_map *map)
{
	int	i;

	i = -1;
	free(map->name);
	if (map->matrix != NULL)
	{
		while (map->matrix[++i] != NULL)
			free(map->matrix[i]);
		free(map->matrix);
	}
	free(map);
}

void	clear_game(t_game *g)
{
	if (g->map != NULL)
		clear_map(g->map);
	if (g->mlx != NULL)
		clear_mlx(g);
	free(g);
	exit(0);
}
