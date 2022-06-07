/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:22:51 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 13:32:51 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_walls(t_game *game)
{
	t_img	*w;
	int		i;
	t_mlx	*m;

	game->walls = malloc(sizeof(t_img) * 1);
	w = game->walls;
	m = game->mlx;
	w[0].p = "images/lava.xpm";
	i = -1;
	while (++i < 1)
	{
		w[i].w = 64;
		w[i].h = 64;
		w[i].img = mlx_xpm_file_to_image(m->mlx_ptr, w[i].p, &w[i].w, &w[i].h);
	}
}
