/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:37:05 by ehode             #+#    #+#             */
/*   Updated: 2025/11/07 09:29:08 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "location.h"

typedef enum e_tile
{
	AIR = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	START = 'P',
	FILL = 'X'
}			t_tile;
typedef struct s_map
{
	t_location	size;
	t_location	start;
	size_t		collectible;
	char		**grid;
}				t_map;
t_map	load_map(char *path);
t_map	new_map(void);
void	destroy_map(t_map *map);
t_map	clone_map(const t_map src_map);
void	show_map(t_map map);
int		is_valid_map(t_map *map);
int		map_flood_fill(t_map *map);
t_tile	get_tile(const t_map map, size_t x, size_t y);

#endif