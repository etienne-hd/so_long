/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:36:43 by ehode             #+#    #+#             */
/*   Updated: 2025/11/01 01:54:25 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	new_map()
{
	t_map	map;

	map.size.x = 0;
	map.size.y = 0;
	map.start.x = 0;
	map.start.y = 0;
	map.collectible = 0;
	map.map = NULL;
	return (map);
}

void	destroy_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size.y && map->map)
		free(map->map[i++]);
	free(map->map);
	map->map = NULL;
}

t_map	clone_map(const t_map map)
{
	t_map	clone_map;
	size_t	i;
	
	clone_map = map;
	clone_map.map = ft_calloc(map.size.y, sizeof(char *));
	if (!clone_map.map)
		return (clone_map);
	i = 0;
	while (i < map.size.y)
	{
		clone_map.map[i] = ft_strdup(map.map[i]);
		if (clone_map.map[i] == NULL)
		{
			destroy_map(&clone_map);
			return (clone_map);
		}
		i++;
	}
	return (clone_map);
}

void	show_map(t_map map)
{
	size_t	i;

	if (map.map == NULL)
	{
		ft_dprintf(2, "Error\nUnable to show map (map not loaded).\n");
		return ;
	}
	ft_printf("Collectible: %d\n", map.collectible);
	i = 0;
	while (i < map.size.y)
	{
		write(1, map.map[i], map.size.x);
		write(1, "\n", 1);
		i++;
	}
}