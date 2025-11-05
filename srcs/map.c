/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:36:43 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 02:56:52 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

t_map	new_map(void)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	return (map);
}

void	destroy_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size.y && map->grid)
		free(map->grid[i++]);
	free(map->grid);
	map->grid = NULL;
}

t_map	clone_map(const t_map map)
{
	t_map	clone_map;
	size_t	i;

	clone_map = map;
	clone_map.grid = ft_calloc(map.size.y, sizeof(char *));
	if (!clone_map.grid)
		return (clone_map);
	i = 0;
	while (i < map.size.y)
	{
		clone_map.grid[i] = ft_strdup(map.grid[i]);
		if (clone_map.grid[i] == NULL)
		{
			destroy_map(&clone_map);
			return (clone_map);
		}
		i++;
	}
	return (clone_map);
}

t_tile	get_tile(const t_map map, size_t x, size_t y)
{
	return (map.grid[y][x]);
}

void	show_map(t_map map)
{
	size_t	i;

	if (map.grid == NULL)
	{
		ft_dprintf(2, "Error\nUnable to show map (map not loaded).\n");
		return ;
	}
	ft_printf("Collectible: %d\n", map.collectible);
	i = 0;
	while (i < map.size.y)
	{
		write(1, map.grid[i], map.size.x);
		write(1, "\n", 1);
		i++;
	}
}
