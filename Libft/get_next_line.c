/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:46:59 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:34:25 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reads from a file descriptor and appends the data to a saved string.
 * 
 * This function reads data from the given file descriptor `fd` into a buffer
 * and appends it to the `save` string until a newline character is found or
 * the end of the file is reached. The function dynamically allocates memory
 * for the buffer and ensures proper null-termination of the string.
 * 
 * @param fd The file descriptor to read from.
 * @param save A pointer to the string where the read data will be appended.
 *             This string should be dynamically allocated or NULL.
 * 
 * @return A pointer to the updated `save` string containing the appended data,
 *         or NULL if an error occurs (e.g., memory allocation failure or read error).
 *         The caller is responsible for freeing the returned string.
 */
static char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	ssize_t	reads;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	reads = 1;
	while (!ft_strchr(save, '\n') && reads > 0)
	{
		reads = read(fd, buffer, BUFFER_SIZE);
		if (reads == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reads] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

/**
 * save_next_line - Extracts and saves the portion of a string after a newline
 *                  character, freeing the original string in the process.
 *
 * @save: A pointer to the string containing the data to process. This string
 *        is expected to contain a newline character if further processing
 *        is required.
 *
 * Return: A newly allocated string containing the portion of the input string
 *         after the first newline character. If no newline is found, or if
 *         memory allocation fails, NULL is returned. The original string
 *         is freed regardless of the outcome.
 *
 * Note: The caller is responsible for freeing the returned string to avoid
 *       memory leaks.
 */
static char	*save_next_line(char *save)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	while (save[i])
	{
		buffer[j++] = save[i++];
	}
	buffer[j] = '\0';
	free(save);
	return (buffer);
}

/**
 * @brief Extracts a line from the given string up to and including the first newline character.
 *
 * This function takes a string `save` and extracts the first line from it, including the newline
 * character if present. The extracted line is returned as a newly allocated string. If the input
 * string is empty or memory allocation fails, the function returns NULL.
 *
 * @param save The input string from which the line is to be extracted.
 *             It is expected to be a null-terminated string.
 *
 * @return A newly allocated string containing the extracted line, including the newline character
 *         if present. Returns NULL if the input string is empty or if memory allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated for the returned string.
 */
static char	*get_the_line(char *save)
{
	int		i;
	char	*buffer;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	buffer = (char *)malloc(i + 2);
	if (!buffer)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/**
 * get_next_line - Reads a line from a file descriptor.
 * 
 * @fd: The file descriptor to read from.
 * @go: A flag to indicate whether to free the static buffer.
 *      If go == 1, the static buffer for the given file descriptor is freed.
 * 
 * This function reads from the file descriptor and returns a single line
 * (including the newline character, if present). It uses a static buffer
 * to store the remaining data for subsequent calls. If the `go` parameter
 * is set to 1, the static buffer for the given file descriptor is freed,
 * and the function returns NULL.
 * 
 * Return: A pointer to the line read from the file descriptor, or NULL
 *         if an error occurs, the end of the file is reached, or the
 *         static buffer is freed.
 */
char	*get_next_line(int fd, int go)
{
	static char	*save[1024];
	char		*line;

	if (go == 1)
	{
		free(save[fd]);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_the_line(save[fd]);
	save[fd] = save_next_line(save[fd]);
	return (line);
}
