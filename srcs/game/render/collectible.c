/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 05:01:46 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 04:31:58 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "location.h"
#include "texture.h"

void	game_render_collectible(t_game *game, long int x, long int y)
{
	int			value;
	t_location	location;
	t_texture	*texture;

	location.x = x;
	location.y = y;
	value = game->seed + y + x;
	if (value % 4 == 0)
		texture = get_texture(game, "assets/collectible1.png");
	else if (value % 4 == 1)
		texture = get_texture(game, "assets/collectible2.png");
	else if (value % 4 == 2)
		texture = get_texture(game, "assets/collectible3.png");
	else
		texture = get_texture(game, "assets/collectible4.png");
	game_render(game, location, texture, 0.0f);
}
