/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:05:50 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/11 19:33:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_addfront(char *pre, char *mid, char *pos)
{
	int		i;
	int		n_i;
	char	*new;

	i = 0;
	n_i = 0;
	new = ft_calloc(ft_strlen(pos)
			+ ft_strlen(pre) + ft_strlen(mid) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (pre[i])
		new[n_i++] = pre[i++];
	i = 0;
	while (mid && mid[i])
		new[n_i++] = mid[i++];
	i = 0;
	while (pos && pos[i])
		new[n_i++] = pos[i++];
	ft_back2zero(&mid, &pos, &pre, NULL);
	return (new);
}

long	ft_back2zero(char **pre_line, char **tmp,
	char **pos, char *last_read)
{
	int	i;

	i = 0;
	while (last_read && i <= BUFFER_SIZE)
		last_read[i++] = 0;
	if (pre_line && *pre_line)
	{
		free(*pre_line);
		*pre_line = NULL;
	}
	if (tmp && *tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	if (pos && *pos)
	{
		free(*pos);
		*pos = NULL;
	}
	return (0);
}

static void	ft_erease_front(int lr_i, char *last_read)
{
	int		i;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	while (i <= BUFFER_SIZE)
		buffer[i++] = 0;
	i = 0;
	while (last_read[lr_i])
		buffer[i ++] = last_read[lr_i ++];
	i = 0;
	while (i <= BUFFER_SIZE)
		last_read[i++] = 0;
	i = 0;
	lr_i = 0;
	while (buffer[i])
		last_read[lr_i ++] = buffer[i ++];
}

static char	*ft_check_last_read(char *last_read, char *line)
{
	char	*new_line;
	char	*tmp;
	int		i;
	int		lr_i;

	i = 0;
	lr_i = 0;
	new_line = ft_strchr(last_read, '\n');
	if (!new_line)
	{
		while (last_read[lr_i])
			line[i ++] = last_read[lr_i ++];
		ft_erease_front(lr_i, last_read);
		return (line);
	}
	tmp = line;
	line = ft_calloc(new_line - last_read + 2, sizeof(char));
	ft_back2zero(&tmp, NULL, NULL, NULL);
	if (!line)
		return (NULL);
	while (last_read[lr_i] != '\n')
		line[i ++] = last_read[lr_i ++];
	line[i] = last_read[lr_i ++];
	ft_erease_front(lr_i, last_read);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	last_read[BUFFER_SIZE + 1];
	char		*line;
	char		*pre_line;
	char		*tmp_line;
	int			check_read;

	pre_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tmp_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_check_last_read(last_read, pre_line);
	if (line != pre_line)
		ft_back2zero(NULL, &tmp_line, NULL, NULL);
	if (line != pre_line)
		return (line);
	check_read = read(fd, tmp_line, BUFFER_SIZE);
	line = ft_handle_nl(tmp_line, last_read, check_read);
	if ((check_read < 1 && !*pre_line) || check_read == -1)
		return ((void *)ft_back2zero(&pre_line, &tmp_line, NULL, last_read));
	else if (line || !check_read)
	{
		line = ft_addfront(pre_line, line, NULL);
		ft_back2zero(&tmp_line, NULL, NULL, NULL);
	}
	else
		line = ft_addfront(pre_line, tmp_line, get_next_line(fd));
	return (line);
}

// *Los saque por las lineas
	// if (!pre_line || !tmp_line)
	// 	return ((void *)(0));