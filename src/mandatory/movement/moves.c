/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:56 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/16 14:28:47 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_player(t_game *g, int dest_x, int dest_y)
{
	display_steps(g);
	if (g->map->matrix[dest_y][dest_x] == 'E')
	{
		if (g->map->nb_col == 0)
			ft_error(31, g);
	}
	return (0);
}

void	move_right(t_game *g)
{
	check_player(g, g->player->x, g->player->y - 1);
	erase_sprite_previous_pos(g);
	add_escape(g);
	move_player_right(g, g->player->x, g->player->y);
}

void	move_left(t_game *g)
{
	check_player(g, g->player->x - 2, g->player->y - 1);
	erase_sprite_previous_pos(g);
	add_escape(g);
	move_player_left(g, g->player->x, g->player->y);
}

void	move_up(t_game *g)
{
	check_player(g, g->player->x - 1, g->player->y - 2);
	erase_sprite_previous_pos(g);
	add_escape(g);
	move_player_up(g, g->player->x, g->player->y);
}

void	move_down(t_game *g)
{
	check_player(g, g->player->x - 1, g->player->y);
	erase_sprite_previous_pos(g);
	add_escape(g);
	move_player_down(g, g->player->x, g->player->y);
}
