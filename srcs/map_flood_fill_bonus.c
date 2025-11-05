/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:36:43 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 03:18:32 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

static int	is_playable(t_map map)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (y < map.size.y - 1)
	{
		x = 1;
		while (x < map.size.x - 1)
		{
			if (
				map.grid[y][x] == EXIT
				|| map.grid[y][x] == COLLECTIBLE
			)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	process(t_map *map, size_t x, size_t y)
{
	map->grid[y][x] = 'X';
	if (map->grid[y][x + 1] != WALL && map->grid[y][x + 1] != FILL
		&& map->grid[y][x + 1] != '!')
		process(map, x + 1, y);
	if (map->grid[y][x - 1] != WALL && map->grid[y][x - 1] != FILL
		&& map->grid[y][x - 1] != '!')
		process(map, x - 1, y);
	if (map->grid[y + 1][x] != WALL && map->grid[y + 1][x] != FILL
		&& map->grid[y + 1][x] != '!')
		process(map, x, y + 1);
	if (map->grid[y - 1][x] != WALL && map->grid[y - 1][x] != FILL
		&& map->grid[y - 1][x] != '!')
		process(map, x, y - 1);
}

int	map_flood_fill(t_map *map)
{
	t_map	flood_fill_map;
	int		valid;

	flood_fill_map = clone_map(*map);
	if (flood_fill_map.grid == NULL)
	{
		ft_dprintf(2, "Error\nAllocation failed.\n");
		return (1);
	}
	process(&flood_fill_map, map->start.x, map->start.y);
	valid = is_playable(flood_fill_map);
	destroy_map(&flood_fill_map);
	return (valid);
}
