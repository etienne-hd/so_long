/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:44:37 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 03:29:51 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "location.h"
#include "map.h"
#include "texture.h"
#include <stddef.h>

static void	game_render_patrol(t_game *game, t_location location)
{
	t_texture	*texture;

	if (game->frame % 30 < 15)
		texture = get_texture(game, "assets/patrol1.png");
	else
		texture = get_texture(game, "assets/patrol2.png");
	game_render(game, location, texture, 0.0f);
}

void	game_render_patrols(t_game *game)
{
	size_t		x;
	size_t		y;
	t_location	location;

	y = 0;
	while (y < game->map->size.y)
	{
		x = 0;
		while (x < game->map->size.x)
		{
			if (game->map->grid[y][x] == '!')
			{
				location.x = x;
				location.y = y;
				game_render_patrol(game, location);
			}
			x++;
		}
		y++;
	}
}
