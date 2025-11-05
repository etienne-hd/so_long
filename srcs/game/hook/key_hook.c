/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:13:17 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 03:24:38 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	game_key_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 41)
		mlx_loop_end(game->mlx);
	else if (key == 26 || key == 82)
		game_on_move(UP, game);
	else if (key == 4 || key == 80)
		game_on_move(LEFT, game);
	else if (key == 22 || key == 81)
		game_on_move(DOWN, game);
	else if (key == 7 || key == 79)
		game_on_move(RIGHT, game);
}
