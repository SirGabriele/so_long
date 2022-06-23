/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:43:24 by kbrousse          #+#    #+#             */
/*   Updated: 2022/06/16 14:35:42 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_base(int error)
{
	char	*error_base[11];

	error_base[1] = "Wrong number of arguments.";
	error_base[2] = "mlx_ptr == NULL.";
	error_base[3] = "win_ptr == NULL.";
	error_base[4] = "";
	error_base[5] = "";
	error_base[6] = "";
	error_base[7] = "";
	error_base[8] = "";
	error_base[9] = "";
	ft_printf("Error\n");
	ft_printf("[ BASE ERROR DETECTED ] : %s\n", error_base[error]);
}

static void	error_file(int error)
{
	char	*error_file[11];

	error_file[0] = "Need a Map with '.ber' extension.";
	error_file[1] = "Encountered an issue while opening file.";
	error_file[2] = "Encountered an issue while closing file.";
	error_file[3] = "File is empty.";
	error_file[4] = "";
	error_file[5] = "";
	error_file[6] = "";
	error_file[7] = "";
	error_file[8] = "";
	error_file[9] = "";
	ft_printf("Error\n");
	ft_printf("[ FILE ERROR DETECTED ] : %s\n", error_file[error % 10]);
}

static void	error_map(int error)
{
	char	*error_map[11];

	error_map[0] = "Map's height is too short.";
	error_map[1] = "Map's width is too short.";
	error_map[2] = "Map's boundaries must be closed.";
	error_map[3] = "Provided map is not a perfect rectangle.";
	error_map[4] = "Unknown symbol on the map.";
	error_map[5] = "Map requires at least one E, one P and one C.";
	error_map[6] = "";
	error_map[7] = "";
	error_map[8] = "";
	error_map[9] = "";
	ft_printf("Error\n");
	ft_printf("[ MAP ERROR DETECTED ] : %s\n", error_map[error % 10]);
}

static void	error_endgame(int error)
{
	char	*error_endgame[11];

	error_endgame[0] = "";
	error_endgame[1] = "You completed the TIG and told Olivier, congrats !";
	error_endgame[2] = "";
	error_endgame[3] = "";
	error_endgame[4] = "";
	error_endgame[5] = "";
	error_endgame[6] = "";
	error_endgame[7] = "";
	error_endgame[8] = "";
	error_endgame[9] = "";
	ft_printf("[ Game stopped ] : %s\n", error_endgame[error % 10]);
}

void	ft_error(int error, t_game *game)
{
	if (error == 0)
		return ;
	else if (1 <= error && error <= 9)
		error_base(error);
	else if (10 <= error && error <= 19)
		error_file(error);
	else if (20 <= error && error <= 29)
		error_map(error);
	else if (30 <= error && error <= 39)
		error_endgame(error);
	clear_game(game);
}
