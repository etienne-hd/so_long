/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:59:51 by ehode             #+#    #+#             */
/*   Updated: 2025/11/01 02:14:16 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_map(t_map *map, char *path)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	map->map = malloc(map->size.y * sizeof(char *));
	y = 0;
	while (1 && map->map)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map->map[y] = line;
		y++;
	}
	close(fd);
	if (!map->map)
		return (1);
	return (0);
}

static void	init_map_tile(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < map->size.y - 1)
	{
		j = 1;
		while (j < map->size.x - 1)
		{
			if (map->map[i][j] == COLLECTIBLE)
				map->collectible++;
			if (map->map[i][j] == START)
			{
				map->start.x = j;
				map->start.y = i;
			}
			j++;
		}
		i++;
	}
}

static int	init_map_size(t_map *map, char *path)
{
	int		fd;
	char	*line;
	size_t	line_length;
	int		error;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	error = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		line_length = ft_linelen(line);
		if (map->size.x == 0)
			map->size.x = line_length;
		else if (map->size.x != line_length)
			error = 1;
		free(line);
		map->size.y++;
	}
	close(fd);
	return (error);
}

t_map	load_map(char *path)
{
	t_map	map;

	map = new_map();
	if (!ft_endwith(path, ".ber"))
	{
		ft_dprintf(2, "Error\nFile must be ending with .ber.\n");
		return (map);
	}
	if (!is_readable_file(path))
	{
		ft_dprintf(2, "Error\nUnable to access to '%s' file.\n", path);
		return (map);
	}
	if (init_map_size(&map, path) || (map.size.x <= 2 || map.size.y <= 2))
	{
		ft_dprintf(2, "Error\nInvalid map size.\n");
		return (map);
	}
	if (init_map(&map, path))
	{
		ft_dprintf(2, "Error\nAllocation failed.\n");
		return (map);
	}
	init_map_tile(&map);
	return (map);
}
