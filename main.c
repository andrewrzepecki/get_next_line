/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:06:23 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/13 14:53:12 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int i;
	int fd;
	char **line;

	i = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			get_next_line(fd, line);
			if (line && *line)
				ft_putstr(*line);
			i++;
		}
	}
	return (0);
}