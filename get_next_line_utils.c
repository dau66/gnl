/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:57:50 by ksho              #+#    #+#             */
/*   Updated: 2023/10/18 16:24:27 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

static char	*ft_append_word(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;

	if (!start)
	{
		start = (char *)malloc(1 * sizeof(char));
		if (!start)
			return (NULL);
		start[0] = '\0';
	}
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
	if (!ptr)
	{
		free(start);
		return (NULL);
	}
	ptr = ft_append_word(ptr, start, buff);
	free(start);
	return (ptr);
}

char	*ft_strncpy_modoki(char *s1, char *s2, size_t i)
{
	size_t	j;

	j = 0;
	while (s2[i + j])
	{
		s1[j] = s2[i + j];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}
