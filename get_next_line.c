/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:57:44 by ksho              #+#    #+#             */
/*   Updated: 2023/09/29 22:43:59 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_nl_until_count(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_set_line(char *start, char *tmp)
{
	size_t	i;
	char	*line;

	free(tmp);
	if (!start || start[0] == '\0')
		return (NULL);
	i = ft_nl_until_count(start);
	line = (char *)malloc((1 + i) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_move_line(char *start, char *tmp)
{
	char	*new_buff;
	size_t	i;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0' || !tmp)
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(sizeof(char) *(ft_strlen(start) - i + 1));
	if (!new_buff)
	{
		free(start);
		return (NULL);
	}
	new_buff = ft_strncpy_modoki(new_buff, start, i);
	free(start);
	return (new_buff);
}

static void	*ft_all_free(char *str, char *str1)
{
	if (str)
		free(str);
	else if (str1)
		free(str1);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	ssize_t		fd_can_read;
	static char	*start_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_can_read = 1;
	tmp = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!tmp)
		return (ft_all_free(tmp, start_str));
	while (!(ft_strchr(start_str, '\n')) && fd_can_read != 0)
	{
		fd_can_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_can_read == -1)
			return (ft_all_free(start_str, tmp));
		tmp[fd_can_read] = '\0';
		start_str = ft_strjoin(start_str, tmp);
		if (!start_str)
			return (ft_all_free(start_str, tmp));
	}
	tmp = ft_set_line(start_str, tmp);
	start_str = ft_move_line(start_str, tmp);
	if (!start_str)
		return (ft_all_free(start_str, tmp));
	return (tmp);
}
