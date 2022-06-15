/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:51:47 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/31 17:58:31 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement_processing(t_game *g, int res, int dest_x, int dest_y)
{
	if (res == 'C')
	{
		g->map->nb_col--;
		g->map->matrix[dest_y][dest_x] = 0;
	}
	else if (res == 'E')
	{
		if (g->map->nb_col == 0)
			ft_error(31, g);
	}
}
