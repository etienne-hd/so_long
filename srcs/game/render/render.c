/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:23:10 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 19:01:38 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	game_render(t_game *game, t_location location,
	t_texture *texture, float angle)
{
	if (texture->x <= 0 || texture->y <= 0 || location.x >= game->map->size.x || location.y >= game->map->size.y)
		return ;
	mlx_put_transformed_image_to_window(
		game->mlx, game->win, 
		texture->texture, 
		location.x * TEXTURE_SIZE, 
		location.y * TEXTURE_SIZE,
		(float)TEXTURE_SIZE / texture->x,
		(float)TEXTURE_SIZE / texture->y,
		angle
	);
}