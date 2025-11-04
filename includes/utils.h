/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:15:51 by ehode             #+#    #+#             */
/*   Updated: 2025/11/04 05:18:52 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
#include <stdlib.h>
#include <sys/time.h>

size_t		ft_linelen(char *str);
int			is_readable_file(const char *path);
long int	get_timestamp(void);
#endif