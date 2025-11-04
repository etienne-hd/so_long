/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:44:37 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 05:36:27 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	game_render_player(t_game *game)
{
	t_texture	*texture;

	if (game->frame % 12 < 3)
		texture = get_texture(game, "assets/player1.png");
	else if (game->frame % 12 < 6)
		texture = get_texture(game, "assets/player2.png");
	else if (game->frame % 12 < 9)
		texture = get_texture(game, "assets/player3.png");
	else
		texture = get_texture(game, "assets/player2.png");
	if (game->player->current_move == DOWN)
		game_render(game, game->player->pos, texture, 0.0f + 90);
	else if (game->player->current_move == LEFT)
		game_render(game, game->player->pos, texture, 90.0f + 90);
	else if (game->player->current_move == UP)
		game_render(game, game->player->pos, texture, 180.0f + 90);
	else if (game->player->current_move == RIGHT)
		game_render(game, game->player->pos, texture, 270.0f + 90);
}