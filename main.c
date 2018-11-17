/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:06:23 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/16 18:35:52 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int i;
	int fd;
    int fd2;
	char *line;
    int     c;

	i = 1;
	if (ac > 1)
	{
        fd = open(av[i], O_RDONLY);
        fd2 = open(av[i + 1], O_RDONLY);
		while (i < ac - 1)
		{
            c = -1;
            while (++c < 4)
            {
			    get_next_line(fd, &line);
			    ft_putendl(line);
                get_next_line(fd2, &line);
                ft_putendl(line);
            }
			i++;
		}
	}
	return (0);
}
