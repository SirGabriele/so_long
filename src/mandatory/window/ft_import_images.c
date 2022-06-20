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

void	ft_import_images(t_game *g)
{
	init_walls(g);
	init_tiles(g);
	init_collects(g);
	init_escapes(g);
	init_char(g);
	init_numbers(g);
}
