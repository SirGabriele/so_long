/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:33:40 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 13:35:24 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_tiles(t_game *game)
{
	t_img	*t;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->tiles = malloc(sizeof(t_img) * 1);
	t = game->tiles;
	t[0].p = "images/tiles.xpm";
	i = -1;
	while (++i < 1)
	{
		t[i].w = 64;
		t[i].h = 64;
		t[i].img = mlx_xpm_file_to_image(m->mlx_ptr, t[i].p, &t[i].w, &t[i].h);
	}	
}
