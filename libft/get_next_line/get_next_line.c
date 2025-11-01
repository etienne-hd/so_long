/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:23:11 by ehode             #+#    #+#             */
/*   Updated: 2025/10/31 19:16:56 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **str)
{
	char	*endline;
	char	*line;
	char	*temp;

	endline = gnl_ft_strchr(*str, '\n');
	line = gnl_ft_strndup(*str, endline - *str + 1);
	if (!line)
		return (NULL);
	temp = *str;
	*str = gnl_ft_strndup(endline + 1, gnl_ft_strlen(endline));
	free(temp);
	if (!*str)
		return (NULL);
	return (line);
}

int	read_fd(char **str, int fd)
{
	char		*buffer;
	int			code;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	code = read(fd, buffer, BUFFER_SIZE);
	if (code > 0)
	{
		buffer[code] = '\0';
		*str = gnl_ft_strjoin(*str, buffer);
	}
	free(buffer);
	if (!*str)
		return (-1);
	return (code);
}

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			code;

	if (fd < 0)
		return (NULL);
	while (!gnl_ft_strchr(str, '\n'))
	{
		code = read_fd(&str, fd);
		if (code <= 0)
		{
			line = NULL;
			if (str && gnl_ft_strlen(str) > 0 && code != -1)
				line = gnl_ft_strndup(str, gnl_ft_strlen(str));
			if (str)
				free_str(&str);
			return (line);
		}
	}
	line = extract_line(&str);
	if (!line)
		free_str(&str);
	return (line);
}
