/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreveren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:59:15 by nreveren          #+#    #+#             */
/*   Updated: 2021/11/20 19:07:38 by nreveren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_find_cr(char *line, char **remains)
{
	char	*lf_ptr;

	lf_ptr = ft_strchr(line, '\n');
	if (lf_ptr)
	{
		*remains = ft_strjoin("", lf_ptr + 1);
		*(lf_ptr + 1) = 0;
	}
	else
		*remains = ((void *)0);
	return (line);
}

static char	*ft_read_fd(int fd, char *pre_line, char **remains)
{
	char	*buf;
	char	*line;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(pre_line, buf);
		free(pre_line);
		ft_bzero(buf, BUFFER_SIZE);
		line = ft_find_cr(line, remains);
		if (*remains)
		{
			free(buf);
			return (line);
		}
		pre_line = line;
	}
	free(buf);
	if (pre_line[0])
		return (pre_line);
	else
	{
		free(pre_line);
		return ((void *) 0);
	}
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*line;

	if (remains)
		line = ft_find_cr(remains, &remains);
	else
		line = ft_calloc(1, sizeof(*line));
	if (!ft_strchr(line, '\n'))
		line = ft_read_fd(fd, line, &remains);
	return (line);
}
