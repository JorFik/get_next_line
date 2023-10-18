/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:44:45 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/18 15:08:46 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line_size(int fd);

char	*get_next_line(int fd)
{
	char	*line;
	int		size;

	size = get_line_size(fd) + 1;
	if (fd < 0 || !size)
		return (0);
	line = malloc(size * sizeof(char));
	if (!line)
		return (0);
	if (!read(fd, line, size))
		return (line);
	else
		line[size - 1] = 0;
	return (line);
}
