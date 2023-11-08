/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:48:02 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/08 15:28:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter) != '\0')
		counter ++;
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

char	*ft_handle_nl(char *line)
{
	char	*nl;
	int		i_nl;

	nl = ft_strchr(line, '\n');
	if (!nl)
		return (NULL);
	i_nl = nl - line + 1;
	while (line[i_nl])
		line[i_nl++] = 0;
	return (line);
}
