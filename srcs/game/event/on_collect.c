/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 01:12:26 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 03:20:59 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "location.h"

void	game_on_collect(t_game *game, t_location location)
{
	game->map->collectible--;
	game->map->grid[location.y][location.x] = AIR;
}
