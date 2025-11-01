/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:45:38 by ehode             #+#    #+#             */
/*   Updated: 2025/10/31 19:49:28 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endwith(char *s, char *end)
{
	size_t	i;
	size_t	s_length;
	size_t	end_length;

	i = 0;
	s_length = ft_strlen(s);
	end_length = ft_strlen(end);
	while (s[s_length - i - 1] == end[end_length - i - 1]
		&& i < s_length && i < end_length)
		i++;
	if (end[i] == '\0')
		return (1);
	return (0);
}