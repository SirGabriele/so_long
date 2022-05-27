/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:44:30 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/26 15:46:31 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_start
{
	int	x;
	int	y;
}	t_start;

typedef struct s_escape
{
	int	x;
	int	y;
}	t_escape;

typedef struct s_collect
{
	int	x;
	int	y;
}	t_collect;

typedef struct s_map
{
	char			*name;
	int				x;
	int				y;
	char			**matrix;
	t_start			*starts;
	int				nb_starts;
	t_escape		*escapes;
	int				nb_escapes;
	t_collect	*collects;
	int				nb_collects;

}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
}	t_game;

void	ft_error(int error, t_game *game);
void	clear_game(t_game *game);

//Init prototypes
void	game_init(t_game *game);
void	map_init(t_map *map);

//files prototypes
void	ft_files_inspector(t_game *game, char **argv);
void	ft_map_parsing(t_game *game);
void	map_save_objects(t_map *map, t_game *game);

//window
void	open_window(t_game *game);
#endif
