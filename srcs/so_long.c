/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:50:03 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 18:08:42 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"
#include "game.h"
#include "libft.h"
#include "texture.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_player	player;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: %s <*.ber>\n", argv[0]);
		return (1);
	}
	map = load_map(argv[1]);
	if (map.grid == NULL)
		return (1);
	if (!is_valid_map(&map))
	{
		destroy_map(&map);
		return (1);
	}
	player = new_player(map.start.x, map.start.y);
	start_game(&map, &player);
	destroy_map(&map);
}
