/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:35:46 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 13:36:50 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_collects(t_game *game)
{
	t_img	*c;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->col = malloc(sizeof(t_img) * 1);
	c = game->col;
	c[0].p = "images/collects.xpm";
	i = -1;
	while (++i < 1)
	{
		c[i].w = 64;
		c[i].h = 64;
		c[i].img = mlx_xpm_file_to_image(m->mlx_ptr, c[i].p, &c[i].w, &c[i].h);
	}
}
