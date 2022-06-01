/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:43:45 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/27 12:09:05 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	game_init(g);
	if (argc < 2)
		ft_error(1, g);
	ft_files_inspector(g, ++argv);
	
	int y = -1;
	int x;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
			ft_printf("%c ", g->map->matrix[y][x]);
		ft_printf("\n");
	}
	ft_printf("\n\n\n");
	change_matrix(g);
	y = -1;
	while (++y < g->map->y)
	{
		x = -1;
		while (++x < g->map->x)
			ft_printf("%c ", g->map->matrix[y][x]);
		ft_printf("\n");
	}
	open_window(g);	
	clear_game(g);
	return (0);
}
