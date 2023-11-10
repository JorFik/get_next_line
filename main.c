/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:35:00 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/10 04:50:02 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;

	fd = open("files/multiple_line_no_nl", O_RDWR);
	printf("	1;	%s	", get_next_line(fd));
	printf("2;	%s	", get_next_line(fd));
	printf("3;	%s	", get_next_line(fd));
	printf("4;	%s	", get_next_line(fd));
	printf("5;	%s	", get_next_line(fd));
	printf("6;	%s	", get_next_line(fd));
	printf("7;	%s	", get_next_line(fd));
	printf("8;	%s	", get_next_line(fd));
	printf("9;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	printf("0;	%s	", get_next_line(fd));
	close (fd);
}
