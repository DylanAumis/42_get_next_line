/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:53:21 by daumis            #+#    #+#             */
/*   Updated: 2023/05/28 17:24:36 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*makeline(char *stash)
{
	char	*line;
	size_t	length;
	size_t	i;

	i = 0;
	line = 0;
	length = ft_strlen(stash);
	line = malloc(length * sizeof(char) + 1);
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	stash = ft_memmove(stash, stash + i, (length - i));
	stash[length - i] = '\0';
	return (line);
}

char	*getstash(int fd, char *stash, ssize_t *len)
{
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (!(ft_strchr(stash, '\n')) && *len == BUFFER_SIZE)
	{
		*len = read(fd, buf, BUFFER_SIZE);
		if (*len == -1)
			return (free(buf), NULL);
		buf[*len] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stash[1024] = {0};
	ssize_t			len;

	len = BUFFER_SIZE;
	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (0);
	stash[fd] = getstash(fd, stash[fd], &len);
	if (ft_strchr(stash[fd], '\n'))
	{
		line = makeline(stash[fd]);
		return (line);
	}
	else if (stash[fd] && *stash[fd] != '\0')
	{
		line = makeline(stash[fd]);
		return (free(stash[fd]), stash[fd] = 0, line);
	}
	return (free(stash[fd]), stash[fd] = 0, line);
}

