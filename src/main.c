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
	t_game	*game;

	game = malloc(sizeof(t_game));
	game_init(game);
	if (argc < 2)
		ft_error(1, game);
	ft_files_inspector(game, ++argv);
	open_window(game);
	clear_game(game);
	return (0);
}
