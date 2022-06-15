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

static void	ft_count_map_y(t_game *g)
{
	char	buf[1];
	int		fd;
	int		hmb_read;

	fd = open(g->map->name, O_RDONLY);
	if (fd == -1)
		ft_error(11, g);
	hmb_read = 1;
	while (hmb_read != 0)
	{
		hmb_read = read(fd, buf, 1);
		if (hmb_read == 0 && g->map->y == 0)
			ft_error(13, g);
		if (buf[0] == '\n')
		{
			buf[0] = '\0';
			g->map->y++;
		}
	}
	if (close(fd) == -1)
		ft_error(12, g);
}

static void	ft_count_map_x(t_game *g)
{
	char	*line;
	int		fd;
	int		i;
	int		count;

	fd = open(g->map->name, O_RDONLY);
	if (fd == -1)
		ft_error(11, g);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i = -1;
		g->map->matrix[count] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		while (line[++i] != '\n' && line[i] != '\0')
			g->map->matrix[count][i] = line[i];
		g->map->x = i;
		free(line);
		line = NULL;
		count++;
	}
	if (close(fd) == -1)
		ft_error(12, g);
}

static void	ft_define_map(char *argv, t_game *g)
{
	g->map->name = ft_strjoin("maps/", argv);
	ft_count_map_y(g);
	if (g->map->y < 3)
		ft_error(20, g);
	g->map->matrix = ft_calloc(g->map->y + 1, sizeof(char *));
	ft_count_map_x(g);
	if (g->map->x < 3)
		ft_error(21, g);
	ft_map_parsing(g);
}

void	ft_files_inspector(t_game *g, char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		ft_error(ft_extension(argv[i++], ".ber"), g);
	g->map = malloc(sizeof(t_map));
	map_init(g->map);
	ft_define_map(argv[0], g);
}
