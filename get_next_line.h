/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahuang <ahuang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 16:00:02 by ahuang        #+#    #+#                 */
/*   Updated: 2022/09/18 18:12:33 by someone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
//# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_aquire_line(char *save_line);
char	*ft_read_line(int fd, char *s);
char	*ft_surplus(char *save_buffer);
char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *string1, char *string2);

#endif
