/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:13:37 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 02:37:50 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "game_bonus.h"
#include "libft.h"
#include "texture.h"
#include <stddef.h>

static char	*itoa_zero(size_t value, size_t n)
{
	char	*s;

	s = ft_calloc(n + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (n)
	{
		s[n - 1] = '0' + value % 10;
		value /= 10;
		n--; 
	}
	return (s);
}

void	game_render_move_count(t_game *game)
{
	char	*move_str;
	
	if (game->player->move > 9999)
	{
		game_on_lose(game);
		return ;
	}
	move_str = itoa_zero(game->player->move, 4);
	if (!move_str)
		return ;
	mlx_set_font_scale(game->mlx, "default", (float)TEXTURE_SIZE / 3);
	mlx_string_put(game->mlx, game->win,
		(game->map->size.x - 2) * TEXTURE_SIZE, TEXTURE_SIZE / 2,
		(mlx_color){ .rgba = 0xFFFFFFFF }, 
		move_str);
	free(move_str);
}