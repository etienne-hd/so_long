/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_lose_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 02:19:24 by ehode             #+#    #+#             */
/*   Updated: 2025/11/05 02:27:12 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"

void	game_on_lose(t_game *game)
{
	mlx_loop_end(game->mlx);
	ft_printf("You Lose!\n");
}