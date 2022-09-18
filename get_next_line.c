/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahuang <ahuang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 15:59:34 by ahuang        #+#    #+#                 */
/*   Updated: 2022/09/18 17:05:12 by someone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *store)
{
	int		reading_nbytes;
	char	*temp_buffer;

	reading_nbytes = 1;
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	while (!ft_strchr(store, '\n') && reading_nbytes != 0)
	{
		reading_nbytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (reading_nbytes < 0)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[reading_nbytes] = 0;
		store = ft_strjoin(store, temp_buffer);
	}
	free(temp_buffer);
	return (store);
}

char	*ft_aquire_line(char *store)
{
	int		i;
	char	*membuffer;

	i = 0;
	if (!store[i]) /* protect if not stored */
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	membuffer = (char *)malloc(sizeof(char) * (i + 2));
	if (!membuffer)
		return (NULL);
	i = 0;
	while (store[i] != '\n' && store[i])
	{
		membuffer[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		membuffer[i] = store[i];
		i++;
	}
	membuffer[i] = 0;
	return (membuffer);
}

char	*ft_surplus_save(char *save_buffer)
{
	int		begin;
	int		i;
	char	*surplus;

	i = 0;
	begin = 0;
	while (save_buffer[i] && save_buffer[i] != '\n')
		i++;
	if (!save_buffer[i])
	{
		free(save_buffer);
		return (NULL);
	}
	surplus = (char *)malloc(sizeof(char) * (ft_strlen(save_buffer) - i + 1 ));
	if (!surplus)
		return (NULL);
	i++;
	while (save_buffer[i])
	{
		surplus[begin] = save_buffer[i];
		begin++;
		i++;
	}
	surplus[begin] = 0;
	free(save_buffer);
	return (surplus);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remaining;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	remaining = ft_read_line(fd, remaining);
	if(!remaining)
		return (NULL);
	line = ft_aquire_line(remaining);
	remaining = ft_surplus_save(remaining);
	return(line);
}
//Test Main!
# include <fcntl.h>
# include <stdio.h>
int main()
{
	char *lines;
	int i;
	int fd;

	i = 1;
	fd = open("tests/test1.txt", O_RDONLY); // change to test1.txt / test2.txt when needed.
	while(i <= 5)
	{
	lines = get_next_line(fd);
	printf("[%03d]: %s", i , lines);
	free (lines);
	i++;
	}
	close(fd);
	return (0);
}
