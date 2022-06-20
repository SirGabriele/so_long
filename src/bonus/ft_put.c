/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:45:22 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/30 19:51:24 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put(t_mlx *mlx2, char *path, int w, int h)
{
	mlx_put_image_to_window(mlx2->mlx_ptr, mlx2->win_ptr, path, w, h);
}
