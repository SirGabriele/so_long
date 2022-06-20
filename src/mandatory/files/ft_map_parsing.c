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

static void	check_symbol(char c, t_game *g)
{
	if (!(c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C'))
		ft_error(24, g);
	else if (c == 'P')
		g->map->nb_starts++;
	else if (c == 'E')
		g->map->nb_esc++;
	else if (c == 'C')
		g->map->nb_col++;	
}

static void	check_first_last_lines(char *line, t_game *g)
{
	int	x;

	x = -1;
	while (line[++x] != '\0')
	{
		if (line[x] != '1' && x < g->map->x)
			ft_error(22, g);
	}
	if (x != g->map->x)
		ft_error(23, g);
}

static void	check_middle_lines(char *line, t_game *g)
{
	int	x;

	x = -1;
	while (line[++x] != '\0')
		check_symbol(line[x], g);
	if (x != g->map->x)
		ft_error(23, g);
	if (line[0] != '1' || line[x - 1] != '1')
		ft_error(22, g);
}

static void	check_map_symbols(char *line, int y, t_game *g)
{
	if (y == 0 || y == g->map->y)
		check_first_last_lines(line, g);
	else
		check_middle_lines(line, g);
}

void	ft_map_parsing(t_game *g)
{
	int	y;

	y = -1;
	while (g->map->matrix[++y])
		check_map_symbols(g->map->matrix[y], y, g);
	if (g->map->nb_starts == 0
		|| g->map->nb_esc == 0
		|| g->map->nb_col == 0)
		ft_error(25, g);
}
