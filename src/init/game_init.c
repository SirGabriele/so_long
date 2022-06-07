/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:47:09 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/26 17:30:20 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_init(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->walls = NULL;
	game->tiles = NULL;
	game->esc = NULL;
	game->col = NULL;
	game->player_img = NULL;
	game->numbers = NULL;
	game->player = NULL;
}
