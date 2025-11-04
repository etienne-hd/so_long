/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:22:43 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 20:16:19 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "texture.h"

void game_on_update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->frame++;
	mlx_clear_window(game->mlx, game->win, (mlx_color){0});
	game_render_map(game);
	game_render_player(game);
	game_render_move_count(game);
}
