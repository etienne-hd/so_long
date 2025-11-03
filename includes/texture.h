/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:35:51 by ehode             #+#    #+#             */
/*   Updated: 2025/11/02 08:21:36 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# ifndef TEXTURE_SIZE
#  define TEXTURE_SIZE 32
# endif
# include "so_long.h"

typedef struct	s_game t_game;

typedef struct	s_texture
{
	int		x;
	int		y;
	mlx_image	texture;
}				t_texture;
t_texture	*load_texture(t_game *game, const char *path);
t_dict		*load_textures(t_game *game);
mlx_image	get_texture(t_game *game, const char *path);
int			check_textures(t_game *game);
void		destroy_textures(t_game *game);

#endif