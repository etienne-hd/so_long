/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:32:52 by ehode             #+#    #+#             */
/*   Updated: 2025/11/02 09:42:36 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "so_long.h"

typedef struct	s_game
{
	mlx_context mlx;
	mlx_window 	win;
	t_map		*map;
	t_player	*player;
	t_dict		*textures;
}				t_game;
typedef enum e_move
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}			t_move;
void	start_game(t_map *map, t_player *player);

// event
void 	game_on_update(void* param);
void	game_on_move(t_move move, t_game *game);
void	game_on_collect(t_game *game, size_t x, size_t y);
void	game_on_exit(t_game *game);

// hook
void	game_key_hook(int key, void* param);
void 	game_window_hook(int event, void *param);

#endif