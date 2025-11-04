/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 02:13:59 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 05:35:49 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "location.h"
#include "map.h"
#include <stddef.h>

static int	is_wall(t_game *game, long int x, long int y)
{
	if (x < 0 || y < 0 
		|| x > game->map->size.x - 1 || y > game->map->size.y - 1)
		return (1);
	return (game->map->grid[y][x] == WALL);
}

static int	game_render_wall_corner(t_game *game, t_location location,
	long int x, long int y)
{
	if (!is_wall(game, x + 1, y + 1))
		game_render(game, location, 
			get_texture(game, "assets/wall_corner.png"), 0.0f);
	if (!is_wall(game, x - 1, y - 1))
		game_render(game, location, 
			get_texture(game, "assets/wall_corner.png"), 180.0f);
	if (!is_wall(game, x - 1, y + 1))
		game_render(game, location, 
			get_texture(game, "assets/wall_corner.png"), 90.0f);
	if (!is_wall(game, x + 1, y - 1))
		game_render(game, location, 
			get_texture(game, "assets/wall_corner.png"), 270.0f);
	return (!is_wall(game, x + 1, y + 1) || !is_wall(game, x - 1, y - 1)
			|| !is_wall(game, x - 1, y + 1) || !is_wall(game, x + 1, y - 1));
}

static int	game_render_wall_side(t_game *game, t_location location,
	long int x, long int y)
{
	if (!is_wall(game, x + 1, y))
		game_render(game, location, 
			get_texture(game, "assets/wall_side.png"), 270.0f);
	if (!is_wall(game, x - 1, y))
		game_render(game, location, 
			get_texture(game, "assets/wall_side.png"), 90.0f);
	if (!is_wall(game, x, y - 1))
		game_render(game, location, 
			get_texture(game, "assets/wall_side.png"), 180.0f);
	if (!is_wall(game, x, y + 1))
		game_render(game, location, 
			get_texture(game, "assets/wall_side.png"), 0.0f);
	return (!is_wall(game, x + 1, y) || !is_wall(game, x - 1, y)
			|| !is_wall(game, x, y - 1) || !is_wall(game, x, y + 1));
}

void	game_render_wall(t_game *game, long int x, long int y)
{
	t_location	location;

	location.x = x;
	location.y = y;
	game_render(game, location, 
		get_texture(game, "assets/wall_surrounded.png"), 0.0f);
	game_render_wall_side(game, location, x, y);
	game_render_wall_corner(game, location, x, y);
}