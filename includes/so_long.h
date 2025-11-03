/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:00:08 by ehode             #+#    #+#             */
/*   Updated: 2025/11/02 07:30:11 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_extended.h"
# include "location.h"
# include "map.h"
# include "player.h"
# include "texture.h"
# include "game.h"

// Parser
t_map	load_map(char *path);

// Utils
size_t	ft_linelen(char *str);
int		is_readable_file(const char *path);

#endif