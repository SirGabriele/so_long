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
	t_collect		*collects;
	int				nb_collects;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
	t_img	*walls;
	t_img	*tiles;
	t_img	*escapes;
	t_img	*collects;
	t_img	*left;
	t_img	*right;
	t_img	*up;
	t_img	*down;
}	t_game;

void	ft_error(int error, t_game *game);
void	clear_game(t_game *game);

//Init prototypes
void	game_init(t_game *game);
void	map_init(t_map *map);
void	init_walls(t_game *game);
void	init_tiles(t_game *game);
void	init_collects(t_game *game);
void	init_char(t_game *game);
void	init_escapes(t_game *game);

//files prototypes
void	ft_files_inspector(t_game *game, char **argv);
void	ft_map_parsing(t_game *game);
void	map_save_objects(t_map *map, t_game *game);

//window
void	open_window(t_game *game);
void	ft_texturing(t_game *game);
void	ft_import_images(t_game *game);
void	ft_put_image(t_game *game);
void	put_collects(t_game *game, int y, int x);
void	put_escape(t_game *game, int y, int x);
void	put_charac(t_game *game, int y, int x);
void	put_tiles(t_game *game, int y, int x);
void	put_wall(t_game *game, int y, int x);
void	ft_put(void *mlx_ptr, void *win_ptr, char *path, int w, int h);

#endif
