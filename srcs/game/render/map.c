/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:45:10 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 05:24:31 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "location.h"
#include "game.h"
#include "texture.h"

static void	put_tile(t_game *game, char tile, size_t x, size_t y)
{
	t_texture	*texture;
	t_location	location;

	location.x = x;
	location.y = y;
	if (tile == WALL)
	{
		game_render_wall(game, x, y);
		return ;
	}
	if (tile == AIR)
		texture = get_texture(game, "assets/air.png");
	if (tile == COLLECTIBLE || tile == START || tile == EXIT)
		put_tile(game, AIR, x, y);
	if (tile == COLLECTIBLE)
	{
		game_render_collectible(game, x, y);
		return ;
	}
	if (tile == START)
		texture = get_texture(game, "assets/air.png");
	if (tile == EXIT)
		texture = get_texture(game, "assets/exit.png");
	game_render(game, location, texture, 0);
}

void	game_render_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map->size.y)
	{
		x = 0;
		while (x < game->map->size.x)
		{
			put_tile(game, get_tile(*game->map, x, y),
				x, y);
			x++;
		}
		y++;
	}
}