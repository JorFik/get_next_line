/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:44:45 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/08 14:00:09 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static void	ft_bzero(void *address, unsigned long size)
{
	if (size <= 0)
		return ;
	else
	{
		*(unsigned char *)address = 0;
		ft_bzero(address + 1, size - 1);
		return ;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*pre_line;
	int			tmp;
	static int	size;

	size += BUFFER_SIZE;
	line = ft_calloc(size + 1, sizeof(char));
	if (!line)
		return (0);
	tmp = read(fd, line, BUFFER_SIZE);
	if (!tmp)
		size = 0;
	if (!tmp)
		return (line);
	if (tmp == -1)
		free (line);
	if (tmp == -1)
		return (NULL);
	pre_line = ft_strchr(line, '\n');
	if (pre_line != NULL)
		ft_bzero(pre_line + 1, ft_strlen(pre_line));
	if (pre_line != NULL)
		size = pre_line - line;
	if (line[size] != '\n')
	{
		free (line);
		pre_line = get_next_line(fd);
		if (pre_line != NULL)
			line = pre_line;
		if (pre_line != NULL)
			size = 0;
	}
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("files/41_no_nl", O_RDWR);
	printf("%s", get_next_line(fd));
	close (fd);
}
