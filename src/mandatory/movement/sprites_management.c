/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:00:58 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/16 14:28:26 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	erase_sprite_previous_pos(t_game *g)
{
	ft_put(g->mlx, g->tiles[0].img, g->map->esc_x * 64, g->map->esc_y * 64);
	ft_put(g->mlx, g->tiles[0]. img, g->player->x * 64, g->player->y * 64);
	if (g->player->x != g->map->esc_x && g->player->y != g->map->esc_y)
		g->map->matrix[g->player->y - 1][g->player->x - 1] = '0';
}
