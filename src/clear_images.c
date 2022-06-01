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

static void	destroy_player(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->left[i].img);
	free(g->left);
	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->right[i].img);
	free(g->right);
	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->up[i].img);
	free(g->up);
	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->down[i].img);
	free(g->down);
}

void	clear_numbers(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 10)
		mlx_destroy_image(g->mlx->mlx_ptr, g->numbers[i].img);
	free(g->numbers);
}

void	clear_images(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->walls[i].img);
	free(g->walls);
	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->tiles[i].img);
	free(g->tiles);
	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->esc[i].img);
	free(g->esc);
	i = -1;
	while (++i < 1)
		mlx_destroy_image(g->mlx->mlx_ptr, g->col[i].img);
	free(g->col);
	i = -1;
	destroy_player(g);
}
