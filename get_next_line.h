/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:07:14 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/03/11 19:06:42 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_read(int fd, char *buffer, char *storage);
char		*ft_make_line(char *storage);
char		*ft_clean_storage(char *storage);
char		*ft_strdup(char *s1);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, size_t start, size_t len);

#endif
