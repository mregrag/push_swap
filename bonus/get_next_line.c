/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:31:26 by mregrag           #+#    #+#             */
/*   Updated: 2024/03/08 13:45:08 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	join_line(char **str, char **buff)
{
	char	*tmp;

	if (!*str)
		*str = ft_strdup("");
	tmp = *str;
	*str = ft_strjoin(tmp, *buff);
	free(tmp);
	tmp = NULL;
}

static char	*get_rest(char *str)
{
	char	*new_str;
	char	*rest;
	int		len;

	rest = ft_strchr(str, '\n');
	if (!rest)
		return (free(str), str = NULL, NULL);
	len = (ft_strlen(str) - ft_strlen(rest)) + 1;
	if (str[len] == '\0')
		return (free(str), str = NULL, NULL);
	new_str = ft_substr(str, len, ft_strlen(str) - len);
	free(str);
	str = NULL;
	if (!new_str)
		return (NULL);
	return (new_str);
}

static char	*get_line(char *str)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(str, '\n');
	len = ft_strlen(str) - ft_strlen(ptr);
	line = ft_substr(str, 0, len + 1);
	return (line);
}

static char	*read_from_file(int fd, char *str)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = malloc(sizeof(char) * ((size_t)42 + 1));
	if (!buffer)
		return (free(str), str = NULL, NULL);
	buffer[0] = '\0';
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read (fd, buffer, 42);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			join_line(&str, &buffer);
		}
	}
	free(buffer);
	buffer = NULL;
	if (bytes == -1)
		return (free(str), str = NULL, NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0)
		return (NULL);
	str = read_from_file(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = get_rest(str);
	return (line);
}
