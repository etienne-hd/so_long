/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:51:34 by ehode             #+#    #+#             */
/*   Updated: 2025/10/30 22:38:33 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(int fd, unsigned int nb, int *count)
{
	if (nb > 9)
		ft_putunbr(fd, nb / 10, count);
	ft_putchar(fd, nb % 10 + '0', count);
}
