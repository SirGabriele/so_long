/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:38:19 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/01 16:40:51 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_numbers(t_game *game)
{
	t_img	*n;
	int		i;
	t_mlx	*m;

	game->numbers = malloc(sizeof(t_img) * 10);
	n = game->numbers;
	m = game->mlx;
	n[0].p = "images/0.xpm";
	n[1].p = "images/1.xpm";
	n[2].p = "images/2.xpm";
	n[3].p = "images/3.xpm";
	n[4].p = "images/4.xpm";
	n[5].p = "images/5.xpm";
	n[6].p = "images/6.xpm";
	n[7].p = "images/7.xpm";
	n[8].p = "images/8.xpm";
	n[9].p = "images/9.xpm";
	i = -1;
	while (++i < 10)
	{
		n[i].w = 16;
		n[i].h = 16;
		n[i].img = mlx_xpm_file_to_image(m->mlx_ptr, n[i].p, &n[i].w, &n[i].h);
	}
}
