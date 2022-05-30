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

#include "../so_long.h"

void	ft_put(void *mlx_ptr, void *win_ptr, char *path, int w, int h)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, path, w, h);
}
