/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:57:32 by ksho              #+#    #+#             */
/*   Updated: 2023/09/29 22:26:42 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_set_line(char *src,char *tmp);
char	*ft_strchr(char *s, int c);
char	*ft_move_line(char *start, char *tmp);
char	*ft_strjoin(char *start, char *buff);
char	*ft_strncpy_modoki(char *s1, char *s2, size_t i);
int		bool_return(char *s);
#endif
