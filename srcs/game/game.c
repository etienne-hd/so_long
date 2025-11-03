/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:36:10 by ehode             #+#    #+#             */
/*   Updated: 2025/11/03 04:51:20 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stddef.h>

static void	destroy(t_game *game)
{
	destroy_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_context(game->mlx);
}

static mlx_window_create_info	get_info(size_t x, size_t y)
{
	mlx_window_create_info	info;

	info.is_fullscreen = 0;
	info.render_target = 0;
	info.title = "so_long";
	info.width = x;
	info.height = y;
	info.is_resizable = false;
	return (info);
}	

void	start_game(t_map *map, t_player *player)
{
	t_game					game;
	mlx_window_create_info	info;

	game.map = map;
	game.player = player;
	game.mlx = mlx_init();
	game.textures = load_textures(&game);
	if (!check_textures(&game))
	{
		ft_dprintf(2, "Error\nUnable to load texture.\n");
		destroy(&game);
		return ;
	}
	info = get_info(map->size.x * TEXTURE_SIZE, map->size.y * TEXTURE_SIZE);
	game.win = mlx_new_window(game.mlx, &info);
	mlx_set_fps_goal(game.mlx, 30);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, game_key_hook, &game);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, game_window_hook, &game);
	mlx_add_loop_hook(game.mlx, game_on_update, &game);
	mlx_loop(game.mlx);
	destroy(&game);
}
