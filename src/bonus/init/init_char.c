/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:38:05 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/07 15:11:40 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_char(t_game *game)
{
	t_img	*p;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->player_img = malloc(sizeof(t_img) * 4);
	p = game->player_img;
	p[0].p = "images/G_Left.xpm";
	p[1].p = "images/G_Up.xpm";
	p[2].p = "images/G_Right.xpm";
	p[3].p = "images/G_Down.xpm";
	i = -1;
	while (++i < 4)
	{
		p[i].w = 64;
		p[i].h = 64;
		p[i].img = mlx_xpm_file_to_image(m->mlx_ptr, p[i].p, &p[i].w, &p[i].h);
	}
}
