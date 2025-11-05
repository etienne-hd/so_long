/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:41:39 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 18:56:55 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "texture.h"
#include "game.h"

const char	*g_textures[] = {
	"assets/air.png",
	"assets/wall_surrounded.png",
	"assets/wall_side.png",
	"assets/wall_corner.png",
	"assets/collectible1.png",
	"assets/collectible2.png",
	"assets/collectible3.png",
	"assets/collectible4.png",
	"assets/exit.png",
	"assets/player1.png",
	"assets/player2.png",
	"assets/player3.png",
	"assets/patrol1.png",
	"assets/patrol2.png",
	NULL
};

t_texture	*load_texture(t_game *game, const char *path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->texture = mlx_new_image_from_file(game->mlx, (char *)path,
			&texture->x, &texture->y);
	return (texture);
}

t_dict	*load_textures(t_game *game)
{
	t_dict		*dict;
	size_t		i;

	dict = ft_dict_new();
	if (!dict)
		return (NULL);
	i = 0;
	while (g_textures[i])
	{
		ft_dict_set(dict, g_textures[i], load_texture(game, g_textures[i]));
		i++;
	}
	return (dict);
}

t_texture	*get_texture(t_game *game, const char *path)
{
	t_texture	*texture;

	texture = ft_dict_get(game->textures, path);
	return (texture);
}

int	check_textures(t_game *game)
{
	size_t		i;
	t_texture	*texture;

	i = 0;
	while (g_textures[i])
	{
		texture = ft_dict_get(game->textures, g_textures[i]);
		if (!texture || !texture->texture)
			return (0);
		i++;
	}
	return (1);
}

void	destroy_textures(t_game *game)
{
	size_t		i;
	t_texture	*texture;

	i = 0;
	while (g_textures[i])
	{
		texture = ft_dict_get(game->textures, g_textures[i]);
		if (texture)
		{
			if (texture->texture)
				mlx_destroy_image(game->mlx, texture->texture);
			free(texture);
		}
		i++;
	}
	ft_dict_clear(&game->textures);
}
