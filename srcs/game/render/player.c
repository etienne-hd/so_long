/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:44:37 by ehode             #+#    #+#             */
/*   Updated: 2025/11/03 21:51:47 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	game_render_player(t_game *game)
{
	mlx_put_image_to_window(
		game->mlx, game->win, 
		get_texture(game, "assets/player.bmp"), 
		game->player->pos.x * TEXTURE_SIZE, 
		game->player->pos.y * TEXTURE_SIZE
	);
}