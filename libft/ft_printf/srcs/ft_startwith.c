/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startwith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:09:57 by ehode             #+#    #+#             */
/*   Updated: 2025/10/30 22:38:41 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_startwith(const char *s, const char *val)
{
	size_t	i;

	i = 0;
	while (s[i] == val[i] && val[i] && s[i])
		i++;
	if (val[i] == '\0')
		return (1);
	return (0);
}
