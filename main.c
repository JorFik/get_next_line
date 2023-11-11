/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:35:00 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/11 19:14:06 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*temp;

	fd = open("files/nl", O_RDONLY);
	printf("	1;	%s	", get_next_line(fd));
	printf("2;	%s	", get_next_line(fd));
	if (BUFFER_SIZE > 100)
	{
		do {
			temp = get_next_line(fd);
		free(temp);
	}
	while (temp != NULL)
		;
}
printf("3;	%s	", get_next_line(-1));
close(fd);
fd = open("files/nl", O_RDONLY);
printf("4;	%s	", get_next_line(fd));
printf("5;	%s	", get_next_line(fd));
printf("6;	%s	", get_next_line(fd));
printf("7;	%s	", get_next_line(fd));
printf("8;	%s	", get_next_line(fd));
}
// * 1 * should be aaaa
// * 2 * should be b
// * 3 * should be NULL
// ! WRONG
// * 4 * should be a
// ! WRONG
// * 5 * should be b
// * 6 * should be c
// * 7 * should be d
// * 8 * should be NULL
// 	int		fd;
// 	char	*tmp;

// 	fd = open("files/nl", O_RDWR);
// printf("	1;	%s	", get_next_line(fd));
// printf("2;	%s	", get_next_line(fd));
// 	do
// 	{
// 		tmp = get_next_line(fd);
// 	free(tmp);
// 	}
// while (tmp != NULL);
// printf("3;	%s	", get_next_line(fd));
// close (fd);
// fd = open("files/multiple_line_with_nl", O_RDWR);
// printf("4;	%s	", get_next_line(fd));
// printf("5;	%s	", get_next_line(fd));
// printf("6;	%s	", get_next_line(fd));
// printf("7;	%s	", get_next_line(fd));
// printf("8;	%s	", get_next_line(fd));
// printf("9;	%s	", get_next_line(fd));
// printf("10;	%s	", get_next_line(fd));
// printf("11;	%s	", get_next_line(fd));
// printf("12;	%s	", get_next_line(fd));
// printf("13;	%s	", get_next_line(fd));
// printf("14;	%s	", get_next_line(fd));
// printf("15;	%s	", get_next_line(fd));
// close (fd);