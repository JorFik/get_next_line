/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:48:02 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/15 21:05:13 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	if (str)
	{
		while (*(str + counter) != '\0')
			counter ++;
	}
	return (counter);
}

void	*ft_calloc(unsigned long count, unsigned long size)
{
	void			*new_p;
	unsigned long	i;

	i = 0;
	new_p = malloc(count * size);
	if (new_p == NULL)
		return (NULL);
	while ((count * size) > i)
	{
		((char *)new_p)[i] = 0;
		i ++;
	}
	return (new_p);
}

char	*ft_strchr(char *src, int c)
{
	int		i;
	char	busco;

	busco = (char) c;
	i = 0;
	while (src[i] != busco && src[i])
		i ++;
	if (src[i] == busco)
		return (&src[i]);
	else
		return (0);
}

char	*ft_handle_nl(char *pre_line, char *last_read, int check_read)
{
	char	*new_line;
	int		nl_i;
	int		i;

	nl_i = 1;
	i = 0;
	new_line = ft_strchr(pre_line, '\n');
	if (!new_line && check_read)
		return (NULL);
	while (check_read && new_line[nl_i])
	{
		last_read[i ++] = new_line[nl_i];
		new_line[nl_i ++] = 0;
	}
	i = 0;
	nl_i = 0;
	if (pre_line[i])
		new_line = ft_calloc(ft_strlen(pre_line) + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	while (pre_line[i])
		new_line[nl_i ++] = pre_line[i ++];
	return (new_line);
}

void	ft_init_lines(char *pre, char *tmp)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		pre[i] = 0;
		tmp[i] = 0;
		i ++;
	}
}

	// nl = ft_strchr(line, '\n');
	// if (!nl)
	// 	return (NULL);
	// while (*(++ nl))
	// 	*nl = 0;
	// return (line);