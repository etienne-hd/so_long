/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:53:00 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 03:22:58 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	move_player(t_move move, t_game *game)
{
	t_location	location;

	location = game->player->pos;
	if (move == UP
		&& get_tile(*game->map, game->player->pos.x,
			game->player->pos.y - 1) != WALL)
		game->player->pos.y--;
	if (move == DOWN
		&& get_tile(*game->map, game->player->pos.x,
			game->player->pos.y + 1) != WALL)
		game->player->pos.y++;
	if (move == LEFT
		&& get_tile(*game->map, game->player->pos.x - 1,
			game->player->pos.y) != WALL)
		game->player->pos.x--;
	if (move == RIGHT
		&& get_tile(*game->map, game->player->pos.x + 1,
			game->player->pos.y) != WALL)
		game->player->pos.x++;
	return (location.x != game->player->pos.x
		|| location.y != game->player->pos.y);
}

void	game_on_move(t_move move, t_game *game)
{
	int		has_moved;
	t_tile	tile;

	game->player->current_move = move;
	has_moved = move_player(move, game);
	tile = get_tile(*game->map, game->player->pos.x, game->player->pos.y);
	if (has_moved)
	{
		game->player->move++;
		ft_printf("%d\n", game->player->move);
		if (tile == COLLECTIBLE)
			game_on_collect(game, game->player->pos);
		else if (tile == EXIT)
			game_on_exit(game);
	}
}
