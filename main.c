/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:35:00 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/08 21:45:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str1;
	char	*str2;

	fd = open("files/alternate_line_nl_no_nl", O_RDWR);
	str1 = get_next_line(fd);
	str2 = get_next_line(fd);
	printf("first;	%sSecond;	%sThird;	%s", str1, str2, get_next_line(fd));
	close (fd);
}
