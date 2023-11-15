/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:34:54 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/15 21:04:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_lines
{
	char	*line;
	char	tmp[BUFFER_SIZE + 1];
	char	pre[BUFFER_SIZE + 1];
}	t_lines;

char			*get_next_line(int fd);
void			*ft_calloc(unsigned long count, unsigned long size);
char			*ft_strchr(char *src, int c);
unsigned long	ft_strlen(const char *str);
char			*ft_handle_nl(char *line, char *last_line, int check_read);
long			ft_back2zero(char **pos, char *last_read);
void			ft_init_lines(char *pre, char *tmp);

#endif