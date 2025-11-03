/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:36:43 by ehode             #+#    #+#             */
/*   Updated: 2025/11/03 17:16:57 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "player.h"

t_player	new_player(size_t x, size_t y)
{
	t_player	player;

	player.pos.x = x;
	player.pos.y = y;
	player.move = 0;
	return (player);
}