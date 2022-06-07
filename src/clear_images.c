/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:16:57 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/01 14:51:18 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_player_patrol_numbers(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(g->mlx->mlx_ptr, g->player_img[i].img);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(g->mlx->mlx_ptr, g->patrol[i].img);
	i = -1;
	while (++i < 10)
		mlx_destroy_image(g->mlx->mlx_ptr, g->numbers[i].img);
	free(g->player_img);
	free(g->patrol);
	free(g->numbers);
}

void	clear_images(t_game *g)
{
	int	i;

	mlx_destroy_image(g->mlx->mlx_ptr, g->walls[0].img);
	mlx_destroy_image(g->mlx->mlx_ptr, g->tiles[0].img);
	mlx_destroy_image(g->mlx->mlx_ptr, g->col[0].img);
	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->esc[i].img);
	free(g->walls);
	free(g->tiles);
	free(g->col);
	free(g->esc);
	clear_player_patrol_numbers(g);
}
