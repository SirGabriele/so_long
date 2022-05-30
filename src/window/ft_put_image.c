/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:34:43 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 16:57:17 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	if_forest(t_game *game, int y, int x)
{
	int	player;
	int	random;

	player = 0;
	random = (int)(rand() / (double)RAND_MAX * (game->map->nb_starts - 1));
	if (game->map->matrix[y][x] == '1')
		put_wall(game, y + 1, x + 1);
	else if (game->map->matrix[y][x] == '0')
		put_tiles(game, y + 1, x + 1);
	else if (game->map->matrix[y][x] == 'P')
	{
		if (player == random)
			put_charac(game, y + 1, x + 1);
		player++;
	}
	else if (game->map->matrix[y][x] == 'E')
		put_escape(game, y + 1, x + 1);
	else if (game->map->matrix[y][x] == 'C')
		put_collects(game, y + 1, x + 1);
}

void	ft_put_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->y)
	{
		x = -1;
		while (++x < game->map->x)
			if_forest(game, y, x);
	}
}
