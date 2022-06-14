/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:56 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/09 20:07:22 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_game *g)
{
	if (g->map->matrix[g->player->y - 1][g->player->x - 2] == 'E')
		clear_game(g);
	erase_sprite_previous_pos(g);
	add_sprite_new_pos(g);
	move_player_right(g, g->player->x, g->player->y);
}

void	move_left(t_game *g)
{
	if (g->map->matrix[g->player->y - 1][g->player->x] == 'E')
		clear_game(g);
	erase_sprite_previous_pos(g);
	add_sprite_new_pos(g);
	move_player_left(g, g->player->x, g->player->y);
}

void	move_up(t_game *g)
{
	if (g->map->matrix[g->player->y - 2][g->player->x - 1] == 'E')
		clear_game(g);
	erase_sprite_previous_pos(g);
	add_sprite_new_pos(g);
	move_player_up(g, g->player->x, g->player->y);
}

void	move_down(t_game *g)
{
	if (g->map->matrix[g->player->y][g->player->x - 2] == 'E')
		clear_game(g);
	erase_sprite_previous_pos(g);
	add_sprite_new_pos(g);
	move_player_down(g, g->player->x, g->player->y);
}
