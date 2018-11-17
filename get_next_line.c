/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:28:45 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/17 16:30:44 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_get_line(char **line, char **s, int fd, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ret == 0 && (s[fd] == NULL || *s[fd] == '\0'))
		return (0);
	while (s[fd][i] != '\0' && s[fd][i] != '\n')
		i++;
	if (s[fd][i] == '\0' && ret != BUFF_SIZE)
	{
		ft_strdel(&(*line));
		*line = ft_strdup(s[fd]);
		return (get_next_line(fd, line));
	}
	else
	{
		ft_strdel(&(*line));
		*line = ft_strndup(s[fd], i);
		tmp = ft_strdup(s[fd] + i + 1);
		ft_strdel(&s[fd]);
		s[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*s[255];
	char			*tmp;
	int				ret;
	int				br;

	if (fd < 0 || !line)
		return (-1);
	br = 1;
	while ((ret = read(fd, &buff, BUFF_SIZE)) && br)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(0);
		if (!(tmp = ft_strjoin(s[fd], buff)))
			return (-1);
		ft_strdel(&s[fd]);
		s[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
		if (ft_strchr(buff, '\n'))
			br = 0;
	}
	return (ft_get_line(line, s, fd, ret));
}
