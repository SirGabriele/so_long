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

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*p;
	int		w;
	int		h;
}	t_img;

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

typedef struct s_player
{
	int	x;
	int	y;
	int	steps;
}	t_player;

typedef struct s_map
{
	char			*name;
	int				x;
	int				y;
	char			**matrix;
	t_start			*starts;
	int				nb_starts;
	t_escape		*esc;
	int				nb_esc;
	t_collect		*col;
	int				nb_col;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	t_mlx		*mlx;
	t_img		*walls;
	t_img		*tiles;
	t_img		*esc;
	t_img		*col;
	t_img		*left;
	t_img		*right;
	t_img		*up;
	t_img		*down;
	t_img		*numbers;
	t_player	*player;
}	t_game;

void	ft_error(int error, t_game *g);
void	clear_game(t_game *g);
void	clear_images(t_game *g);
void	clear_numbers(t_game *g);
void	change_matrix(t_game *g);

//Init prototypes
void	game_init(t_game *g);
void	map_init(t_map *map);
void	init_walls(t_game *g);
void	init_tiles(t_game *g);
void	init_collects(t_game *g);
void	init_char(t_game *g);
void	init_escapes(t_game *g);
void	init_numbers(t_game *g);
void	init_player(t_game *g);

//files prototypes
void	ft_files_inspector(t_game *g, char **argv);
void	ft_map_parsing(t_game *g);
void	map_save_objects(t_map *map);

//window
void	open_window(t_game *g);
void	ft_texturing(t_game *g);
void	ft_import_images(t_game *g);
void	ft_put_image(t_game *g);
void	put_collects(t_game *g, int y, int x);
void	put_escape(t_game *g, int y, int x);
void	put_charac(t_game *g, int y, int x);
void	put_tiles(t_game *g, int y, int x);
void	put_wall(t_game *g, int y, int x);
void	ft_put(t_mlx *mlx2, char *path, int w, int h);
void	move_right(t_game *g, int x, int y);
void	move_left(t_game *g, int x, int y);
void	move_up(t_game *g, int x, int y);
void	move_down(t_game *g, int x, int y);
void	movement_processing(t_game *g, int res, int dest_y, int dest_x);
void	display_steps(t_game *g, int steps);

#endif
