/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:30:55 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/02 18:35:31 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_steps(t_game *g)
{
	g->player->steps++;
	if (g->player->steps > 2000000000)
		g->player->steps = 1;
	ft_printf("%d\n", g->player->steps);
}
