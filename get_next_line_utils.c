/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:04:07 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/03/11 18:35:59 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Memory creation if we don't have.
char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*p;

	p = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

//Len
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

//Find '\n'
char	*ft_strchr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

//Join buffer with storage
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*buf;

	i = 0;
	j = 0;
	buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!buf)
		return (free(s1), NULL);
	while (s1[i] != '\0')
		buf[j++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		buf[i++] = s2[j++];
	buf[i] = '\0';
	free(s1);
	return (buf);
}

//Clean before '\n' && save after '\n'.
char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup (""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
