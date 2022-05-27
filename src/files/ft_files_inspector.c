/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_inspector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:47:56 by kbrousse          #+#    #+#             */
/*   Updated: 2022/05/27 14:34:42 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_count_map_y(t_game *game)
{
	char	buf[1];
	int		fd;
	int		hmb_read;

	fd = open(game->map->name, O_RDONLY);
	if (fd == -1)
		ft_error(11, game);
	hmb_read = 1;
	while (hmb_read != 0)
	{
		hmb_read = read(fd, buf, 1);
		if (hmb_read == 0 && game->map->y == 0)
			ft_error(13, game);
		if (buf[0] == '\n')
		{
			buf[0] = '\0';
			game->map->y++;
		}
	}
	if (close(fd) == -1)
		ft_error(12, game);
}

static void	ft_count_map_x(t_game *game)
{
	char	*line;
	int		fd;
	int		i;
	int		count;

	fd = open(game->map->name, O_RDONLY);
	if (fd == -1)
		ft_error(11, game);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i = -1;
		game->map->matrix[count] = ft_calloc(ft_strlen(line), sizeof(char));
		while (line[++i] != '\n')
			game->map->matrix[count][i] = line[i];
		game->map->x = i;
		free(line);
		line = NULL;
		count++;
	}
	if (close(fd) == -1)
		ft_error(12, game);
}

static void	ft_define_map(char	*argv, t_game *game)
{
	game->map->name = ft_strjoin("maps/", argv);
	ft_count_map_y(game);
	if (game->map->y < 3)
		ft_error(20, game);
	game->map->matrix = ft_calloc(game->map->y + 1, sizeof(char *));
	ft_count_map_x(game);
	if (game->map->x < 3)
		ft_error(21, game);
	ft_map_parsing(game);
}

void	ft_files_inspector(t_game *game, char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		ft_error(ft_extension(argv[i++], ".ber"), game);
	game->map = malloc(sizeof(t_map));
	map_init(game->map);
	ft_define_map(argv[0], game);
}
