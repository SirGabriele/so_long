/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_patrol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:20:50 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/02 14:24:28 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_patrol(t_game *game)
{
	t_img	*p;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->patrol = malloc(sizeof(t_img) * 4);
	p = game->patrol;
	p[0].p = "images/Lawnmower_Left.xpm";
	p[1].p = "images/Lawnmower_Up.xpm";
	p[2].p = "images/Lawnmower_Right.xpm";
	p[3].p = "images/Lawnmower_Down.xpm";
	i = -1;
	while (++i < 4)
	{
		p[i].w = 64;
		p[i].h = 64;
		p[i].img = mlx_xpm_file_to_image(m->mlx_ptr, p[i].p, &p[i].w, &p[i].h);
	}
}
