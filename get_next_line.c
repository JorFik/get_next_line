/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:05:50 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/08 22:00:55 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_addfront(char *pre, char *pos)
{
	int		i;
	int		n_i;
	char	*new;

	i = 0;
	n_i = 0;
	new = ft_calloc(ft_strlen(pos) + ft_strlen(pre) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (pre[i])
		new[n_i++] = pre[i++];
	i = 0;
	while (pos[i])
		new[n_i++] = pos[i++];
	if (pre)
		free(pre);
	if (pos)
		free(pos);
	return (new);
}

char	*get_next_line(int fd)
{
	static int	size;
	char		*line;
	char		*pre_line;
	int			read_succesful;

	size += BUFFER_SIZE;
	pre_line = ft_calloc(size + 1, sizeof(char));
	if (!pre_line)
		return (NULL);
	read_succesful = read(fd, pre_line, BUFFER_SIZE);
	if (read_succesful == -1 || (!read_succesful && size == BUFFER_SIZE))
	{
		free(pre_line);
		size = 0;
		return (NULL);
	}
	if (ft_handle_nl(pre_line) || !read_succesful)
		line = pre_line;
	else
	{
		line = get_next_line(fd);
		line = ft_addfront(pre_line, line);
	}
	size = 0;
	return (line);
}
