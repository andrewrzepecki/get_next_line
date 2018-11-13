/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:28:45 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/13 15:46:42 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE];
	char			*tmp;
	int				ret;
	char			*nl;

	if (!(tmp = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	*tmp = 0;
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, &buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret - 1] = '\0';
		tmp = ft_strjoin(tmp, buff);
		nl = ft_strchr(tmp, '\n');
		if (nl)
		{
			*nl = '\0';
			if(!(line = (char**)malloc(sizeof(char*) * 1)))
				return (-1);
			*line = ft_strdup(tmp);
			return (1);
		}
	}
	return (0);
}