/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:13:54 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 15:00:18 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_import_images(t_game *game)
{
	init_walls(game);
	init_tiles(game);
	init_collects(game);
	init_escapes(game);
	init_char(game);
}
