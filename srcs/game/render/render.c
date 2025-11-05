/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:23:10 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 01:16:00 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"
#include "ft_printf.h"

void	game_render(t_game *game, t_location location,
	t_texture *texture, float angle)
{
	if (!texture || !texture->texture)
	{
		ft_dprintf(2, "Error\nCan't render texture.\n");
		return ;
	}
	if (texture->x == 0 || texture->y == 0)
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