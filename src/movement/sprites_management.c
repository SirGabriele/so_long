/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:00:58 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/09 20:09:34 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	change_dir_patrol(t_game *g)
{
	if (g->patrol->steps == 0)
	{
		if (g->map->matrix[g->patrol->y - 1][g->patrol->x - 2] == '0')
			return;
		g->patrol->steps = 1;
	}
	if (g->patrol->steps == 1)
	{
		if (g->map->matrix[g->patrol->y - 2][g->patrol->x - 1] == '0')
			return;
		g->patrol->steps = 2;
	}
	if (g->patrol->steps == 2)
	{
		if (g->map->matrix[g->patrol->y - 1][g->patrol->x] == '0')
			return;
		g->patrol->steps = 3;
	}
	if (g->patrol->steps == 3)
	{
		if (g->map->matrix[g->patrol->y][g->patrol->x - 1] == '0')
			return;
		g->patrol->steps = 0;
	}
}

/*add the new escape sprite on the screen and its letter on the matrix*/
/*same for the new player's sprite*/

void	add_sprite_new_pos(t_game *g)
{
	change_dir_patrol(g);	
	if (g->patrol->steps == 0)
		add_patrol_left(g);
	else if (g->patrol->steps == 1)
		add_patrol_up(g);
	else if (g->patrol->steps == 2)
		add_patrol_right(g);
	else if (g->patrol->steps == 3)
		add_patrol_down(g);
}

/*erase the previous escape sprite on the screen and its letter on the matrix*/
/*same for the previous player's sprite*/

void	erase_sprite_previous_pos(t_game *g)
{
	ft_put(g->mlx, g->tiles[0].img, g->map->esc_x * 64, g->map->esc_y * 64);
	g->map->matrix[g->map->esc_y - 1][g->map->esc_x - 1] = '0';
	ft_put(g->mlx, g->tiles[0]. img, g->player->x * 64, g->player->y * 64);
	g->map->matrix[g->player->y - 1][g->player->x - 1] = '0';
}
