/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 01:12:26 by ehode             #+#    #+#             */
/*   Updated: 2025/11/03 00:25:09 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_on_collect(t_game *game, size_t x, size_t y)
{
	game->map->collectible--;
	game->map->grid[y][x] = AIR;
}