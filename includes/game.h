/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:32:52 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 05:17:00 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "mlx_extended.h"
# include "mlx.h"
#include "player.h"
# include "texture.h"
# include "map.h"
# include "libft.h"
# include "move.h"

typedef struct	s_game
{
	mlx_context mlx;
	mlx_window 	win;
	t_map		*map;
	t_player	*player;
	t_dict		*textures;
	size_t		frame;
	long int	seed;
}				t_game;

void	start_game(t_map *map, t_player *player);

// event
void 	game_on_update(void* param);
void	game_on_move(t_move move, t_game *game);
void	game_on_collect(t_game *game, t_location location);
void	game_on_exit(t_game *game);

// hook
void	game_key_hook(int key, void* param);
void 	game_window_hook(int event, void *param);

// render
void	game_render_map(t_game *game);
void	game_render_player(t_game *game);
void	game_render_wall(t_game *game, long int x, long int y);
void	game_render_collectible(t_game *game, long int x, long int y);
void	game_render(t_game *game, t_location location,
	t_texture *texture, float angle);

#endif