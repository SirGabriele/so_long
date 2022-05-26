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

static	void	clear_matrix(t_map *map)
{
	int	i;

	i = -1;
	while (map->matrix[++i] != NULL)
		free(map->matrix[i]);
	free(map->matrix);
}

static	void	clear_map(t_map *map)
{
	free(map->name);
	if (map->matrix)
		clear_matrix(map);
	if (map->starts)
		printf("test");
	if (map->escapes)
		printf("test");
	if (map->collectibles)
		printf("test");
	free(map);
}

void	clear_game(t_game *game)
{
	if (game->map)
		clear_map(game->map);
	free(game);
	exit(0);
}
