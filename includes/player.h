/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:37:05 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 22:53:24 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
#include <stdlib.h>
#include "location.h"
# include "move.h"

typedef struct	s_player
{
	t_location	pos;
	size_t		move;
	t_move		current_move;
}				t_player;
t_player	*new_player(size_t x, size_t y);

#endif