/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 08:57:22 by ehode             #+#    #+#             */
/*   Updated: 2025/11/02 08:59:02 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_window_hook(int event, void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	if(event == 0)
		mlx_loop_end(game->mlx);
}