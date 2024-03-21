/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:05:25 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/03/21 16:11:57 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Read fd && save it in storage.
char	*ft_read(int fd, char *buffer, char *storage)
{
	int	read_res;

	if (!storage)
	{
		storage = ft_strdup("");
		if (storage == NULL)
			return (free(buffer), NULL);
	}
	read_res = 1;
	while (ft_strchr(storage) == NULL && read_res > 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res == -1)
			return (free(buffer), free(storage), NULL);
		if (read_res == 0)
			break ;
		buffer[read_res] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (read_res == 0 && storage[0] == '\0')
		return (free(storage), NULL);
	return (storage);
}

//Extract line -> '\n' or '\0' -> add '\0' to finish the line.
char	*ft_make_line(char *storage)
{
	int		i;
	int		j;
	char	*tmp_line;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	tmp_line = malloc(sizeof(char) * (i + 1));
	if (!tmp_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp_line[j] = storage[j];
		j++;
	}
	tmp_line[j] = '\0';
	return (tmp_line);
}

//clean buffer & save the rest after '\n'.
char	*ft_clean_storage(char *storage)
{
	int		i;
	char	*str;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n' )
		i++;
	if (storage[i] == '\n')
		i++;
	str = ft_substr(storage, i, ft_strlen(storage) - i);
	free(storage);
	if (!str)
		return (NULL);
	return (str);
}

//Main function.
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(storage), storage = NULL, NULL);
	storage = ft_read(fd, buffer, storage);
	if (!storage)
		return (NULL);
	line = ft_make_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	storage = ft_clean_storage(storage);
	if (!storage)
		return (free(line), NULL);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int	i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		exit (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line %d: %s",i, line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (line == NULL)
		printf("line %d: %s", i, line);
	return (0);
}
*/
