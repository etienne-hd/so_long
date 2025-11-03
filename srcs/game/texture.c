/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:41:39 by ehode             #+#    #+#             */
/*   Updated: 2025/11/03 17:20:05 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "texture.h"
#include "game.h"

const char *textures[] = {
	"assets/air.bmp", "assets/wall.bmp", "assets/collectible.bmp",
	"assets/start.bmp", "assets/exit.bmp", "assets/player.bmp",
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
	while (textures[i])
	{
		ft_dict_set(dict, textures[i], load_texture(game, textures[i]));
		i++;
	}
	return (dict);
}

mlx_image	get_texture(t_game *game, const char *path)
{
	t_texture	*texture;

	texture = ft_dict_get(game->textures, path);
	return (texture->texture);
}

int	check_textures(t_game *game)
{
	size_t	i;

	i = 0;
	while (textures[i])
	{
		if (!ft_dict_get(game->textures, textures[i]))
			return (0);
		i++;
	}
	return (1);
}

void	destroy_textures(t_game *game)
{
	size_t	i;
	t_texture	*texture;

	i = 0;
	while (textures[i])
	{
		texture = ft_dict_get(game->textures, textures[i]);
		if (texture)
		{
			mlx_destroy_image(game->mlx, texture->texture);
			free(texture);
		}
		i++;
	}
	ft_dict_clear(&game->textures);
}
