/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:44:45 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/08 01:27:11 by JFikents         ###   ########.fr       */
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

char	*ft_r_str(char *src)
{
	char	*new;
	int		size_src;
	int		i;

	i = 0;
	size_src = ft_strlen(src);
	new = ft_calloc(size_src + 1, sizeof(char));
	while (size_src >= 0)
	{
		new[i++] = src[size_src--];
	}
	free(src);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*pre_line;
	int			tmp;
	static int	size;
	// int			t_size;

	size += BUFFER_SIZE;
	line = ft_calloc(size + 1, sizeof(char));
	if (!line)
		return (0);
	// t_size = size + 1;
	tmp = read(fd, line, BUFFER_SIZE);
	if (tmp == -1)
		free (line);
	if (tmp == -1)
		return (NULL);
	if (!tmp)
		return (line);
	pre_line = ft_strchr(line, '\n');
	if (pre_line != NULL)
		ft_bzero(pre_line + 1, ft_strlen(pre_line));
	if (pre_line != NULL)
		size = pre_line - line;
	if (line[size] != '\n')
	{
		pre_line = get_next_line(fd);
		if (pre_line != NULL)
		{
			ft_strlcat(pre_line, line, size);
			free (line);
			return (pre_line);
		}
	}
	size = 0;
	line = ft_r_str(pre_line);
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("files/41_no_nl", O_RDWR);
// 	printf("%s", get_next_line(fd));
// 	close (fd);
// }
