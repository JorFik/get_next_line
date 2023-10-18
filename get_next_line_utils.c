/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:48:02 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/18 13:02:08 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_size(int fd)
{
	int		size;
	char	c;

	size = 0;
	if (fd <= 0)
		return (0);
	while (read (fd, &c, 1) && c != '\n')
		size ++;
	return (size);
}
