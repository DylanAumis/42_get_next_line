/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:53:23 by daumis            #+#    #+#             */
/*   Updated: 2023/05/28 17:17:10 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
		if (*s == c)
			return ((char *)s);
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*pstr;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	pstr = malloc (size * sizeof(char) + 1);
	if (!pstr)
		return (0);
	while (s1 && s1[i])
	{
		pstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		pstr[i++] = s2[j++];
	pstr[i] = '\0';
	free(s1);
	return (pstr);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (src <= dest)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
