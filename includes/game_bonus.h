/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:32:52 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 02:37:40 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H
# include "game.h"

void	game_render_patrols(t_game *game);
void	game_render_move_count(t_game *game);
void	game_on_lose(t_game *game);

#endif