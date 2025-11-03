/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:36:10 by ehode             #+#    #+#             */
/*   Updated: 2025/11/02 09:00:10 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy(t_game *game)
{
	destroy_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_context(game->mlx);
}

void	start_game(t_map *map, t_player *player)
{
	t_game					game;
	mlx_window_create_info	info = {0};

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
	info.title = "so_long";
	info.width = map->size.x * TEXTURE_SIZE;
	info.height = map->size.y * TEXTURE_SIZE;
	info.is_resizable = false;
	game.win = mlx_new_window(game.mlx, &info);
	mlx_set_fps_goal(game.mlx, 30);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, game_key_hook, &game);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, game_window_hook, &game);
	mlx_add_loop_hook(game.mlx, game_on_update, &game);
	mlx_loop(game.mlx);
	destroy(&game);
}
