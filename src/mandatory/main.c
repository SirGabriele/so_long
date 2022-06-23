/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:52:50 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/07 12:53:08 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	game_init(g);
	if (argc != 2)
		ft_error(1, g);
	ft_files_inspector(g, ++argv);
	change_matrix(g);
	open_window(g);
	clear_game(g);
	return (0);
}
