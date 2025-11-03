/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:45:10 by ehode             #+#    #+#             */
/*   Updated: 2025/11/03 21:51:44 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	game_render_map(t_game *game)
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