/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:13:56 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/27 14:35:07 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_symbol(char c, t_game *game)
{
	if (!(c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C'))
		ft_error(23, game);
	else if (c == 'P')
		game->map->nb_starts++;
	else if (c == 'E')
		game->map->nb_escapes++;
	else if (c == 'C')
		game->map->nb_collects++;
}

static void	check_first_last_lines(char *line, t_game *game)
{
	int	x;

	x = -1;
	while (line[++x] != '\0')
	{
		if (line[x] != '1' && x < game->map->x)
			ft_error(22, game);
	}
	if (x != game->map->x)
		ft_error(23, game);
}

static void	check_middle_lines(char *line, t_game *game)
{
	int	x;

	x = -1;
	while (line[++x] != '\0')
		check_symbol(line[x], game);
	if (x != game->map->x)
		ft_error(23, game);
	if (line[0] != '1' || line[x - 1] != '1')
		ft_error(22, game);
}

static void	check_map_symbols(char *line, int y, t_game *game)
{
	if (y == 0 || y == game->map->y)
		check_first_last_lines(line, game);
	else
		check_middle_lines(line, game);
}

void	ft_map_parsing(t_game *game)
{
	int	y;

	y = -1;
	while (game->map->matrix[++y])
		check_map_symbols(game->map->matrix[y], y, game);
	if (game->map->nb_starts == 0
		|| game->map->nb_escapes == 0
		|| game->map->nb_collects == 0)
		ft_error(25, game);
	map_save_objects(game->map, game);
}
