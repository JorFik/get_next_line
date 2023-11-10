/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:01:39 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/10 19:29:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_erease_front(int lr_i, char *last_read)
{
	int	i;

	i = 0;
	while (last_read[lr_i] && i <= BUFFER_SIZE)
	{
		last_read[i ++] = last_read[lr_i];
		last_read[lr_i ++] = 0;
	}
}

static void	ft_make_full(char *last_read)
{
	int	i;
	char num[] = "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25";

	i = 0;
	while (i < BUFFER_SIZE)
	{
		last_read[i] = num[i];
		i ++;
	}
	printf("%s\n", last_read);
	ft_erease_front(10, last_read);
}

int	main(void)
{
	static char	last_read[BUFFER_SIZE + 1];

	ft_make_full(last_read);
	printf("%s\n", last_read);
	ft_make_full(last_read);
	printf("%s\n", last_read);
	ft_make_full(last_read);
	printf("%s\n", last_read);
	ft_make_full(last_read);
	printf("%s\n", last_read);
}
