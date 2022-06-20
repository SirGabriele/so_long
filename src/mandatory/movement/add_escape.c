/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_escape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:58:59 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/16 14:28:07 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_escape(t_game *g)
{
	int	x;
	int	y;

	x = g->map->esc_x;
	y = g->map->esc_y;
	ft_put(g->mlx, g->esc[1].img, x * 64, y * 64);
}
