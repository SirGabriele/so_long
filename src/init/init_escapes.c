/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_escapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:32:14 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 16:32:39 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_escapes(t_game *game)
{
	t_img	*e;
	int		i;
	t_mlx	*m;

	m = game->mlx;
	game->esc = malloc(sizeof(t_img) * 1);
	e = game->esc;
	e[0].p = "images/escape.xpm";
	i = -1;
	while (++i < 1)
	{
		e[i].w = 64;
		e[i].h = 64;
		e[i].img = mlx_xpm_file_to_image(m->mlx_ptr, e[i].p, &e[i].w, &e[i].h);
	}	
}
