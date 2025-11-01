/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:50:03 by ehode             #+#    #+#             */
/*   Updated: 2025/11/01 02:14:38 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (1);
	map = load_map(argv[1]);
	if (map.map == NULL)
		return (1);
	if (!is_valid_map(map))
	{
		destroy_map(&map);
		return (1);
	}
	show_map(map);
	destroy_map(&map);
}
