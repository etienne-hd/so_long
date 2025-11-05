/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:36:43 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 18:54:49 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"
#include "libft.h"
#include "texture.h"

static int	check_border(t_map *map)
{
	size_t	i;

	i = 0;
	while (
		i < map->size.x && map->grid[0][i] == WALL
		&& map->grid[map->size.y - 1][i] == WALL
	)
		i++;
	if (i != map->size.x)
		return (0);
	i = 0;
	while (
		i < map->size.y && map->grid[i][0] == WALL
		&& map->grid[i][map->size.x - 1] == WALL
	)
		i++;
	if (i != map->size.y)
		return (0);
	return (1);
}

static int	check_tile(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	tile[3];

	tile[0] = 0;
	tile[1] = 0;
	tile[2] = 0;
	i = 1;
	while (i < map->size.y - 1)
	{
		j = 1;
		while (j < map->size.x - 1)
		{
			if (map->grid[i][j] == START)
				tile[0]++;
			else if (map->grid[i][j] == EXIT)
				tile[1]++;
			else if (map->grid[i][j] == COLLECTIBLE)
				tile[2]++;
			j++;
		}
		i++;
	}
	return (tile[0] == 1 && tile[1] == 1 && tile[2] >= 1);
}

static int	invalid_tile(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < map->size.y - 1)
	{
		j = 1;
		while (j < map->size.x - 1)
		{
			if (!(map->grid[i][j] == AIR
				|| map->grid[i][j] == WALL
				|| map->grid[i][j] == COLLECTIBLE
				|| map->grid[i][j] == EXIT
				|| map->grid[i][j] == START
			))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_size(t_map *map)
{
	if (map->size.x * TEXTURE_SIZE > 1920
		|| (map->size.y + 2) * TEXTURE_SIZE > 1080)
	{
		ft_dprintf(2, "Error\nMap too big.\n");
		return (0);
	}
	return (1);
}

int	is_valid_map(t_map *map)
{
	if (!check_border(map))
	{
		ft_dprintf(2, "Error\nMap must be enclosed/surrounded by walls.\n");
		return (0);
	}
	if (!check_tile(map))
	{
		ft_dprintf(2, "Error\nMap must contain 1 exit, \
1 starting position and at least 1 collectible\n");
		return (0);
	}
	if (!invalid_tile(map))
	{
		ft_dprintf(2, "Error\nMap contains invalid tile.\n");
		return (0);
	}
	if (!check_size(map))
		return (0);
	if (!map_flood_fill(map))
	{
		ft_dprintf(2, "Error\nMap cannot be played \
(there is no valid path).\n");
		return (0);
	}
	return (1);
}
