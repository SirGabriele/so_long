/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:43:45 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/02 18:34:17 by kbrousse         ###   ########.fr       */
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
	change_matrix(g);
	open_window(g);
	clear_game(g);
	return (0);
}
