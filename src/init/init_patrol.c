/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_patrol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:13:29 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/07 15:12:08 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_patrol(t_game *game)
{
	t_img	*p;
	int		i;
	t_mlx	*m;

	game->patrol = malloc(sizeof(t_img) * 4);
	p = game->patrol;
	m = game->mlx;
	p[0].p = "images/Patrol_Left.xpm";
	p[1].p = "images/Patrol_Up.xpm";
	p[2].p = "images/Patrol_Right.xpm";
	p[3].p = "images/Patrol_Down.xpm";
	i = -1;
	while (++i < 4)
	{
		p[i].w = 64;
		p[i].h = 64;
		p[i].img = mlx_xpm_file_to_image(m->mlx_ptr, p[i].p, &p[i].w, &p[i].h);
	}
}
