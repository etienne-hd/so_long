/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:22:43 by ehode             #+#    #+#             */
/*   Updated: 2025/11/03 17:21:07 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"
#include "texture.h"

static void	put_tile(t_game *game, char tile, size_t x, size_t y)
{
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx, game->win, get_texture(game, "assets/wall.bmp"), x, y);
	if (tile == AIR || tile == COLLECTIBLE || tile == START || tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, get_texture(game, "assets/air.bmp"), x, y);
	if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, get_texture(game, "assets/collectible.bmp"), x, y);
	if (tile == START)
		mlx_put_image_to_window(game->mlx, game->win, get_texture(game, "assets/start.bmp"), x, y);
	if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, get_texture(game, "assets/exit.bmp"), x, y);
}

static void	update_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map->size.y)
	{
		x = 0;
		while (x < game->map->size.x)
		{
			put_tile(game, get_tile(*game->map, x, y),
				x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			x++;
		}
		y++;
	}
}

static void	update_player(t_game *game)
{
	mlx_put_image_to_window(
		game->mlx, game->win, 
		get_texture(game, "assets/player.bmp"), 
		game->player->pos.x * TEXTURE_SIZE, 
		game->player->pos.y * TEXTURE_SIZE
	);
}

void game_on_update(void *param)
{
	t_game	*game;
	mlx_color color = {0};

	game = (t_game *)param;
	mlx_clear_window(game->mlx, game->win, color);
	update_map(game);
	update_player(game);
}
