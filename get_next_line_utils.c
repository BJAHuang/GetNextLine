/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahuang <ahuang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 15:59:23 by ahuang        #+#    #+#                 */
/*   Updated: 2022/09/18 18:06:47 by someone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(char *str, int c)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[x] != '\0')
	{
		if (str[x] == (char) c)
			return ((char *)&str[x]);
		x++;
	}
	return (0);
}

char	*ft_strjoin(char *string1, char *string2)
{
	char	*str;
	size_t	x;
	size_t	i;
	
	if (!string1)
	{
		string1 = (char *)malloc (1 * sizeof(char));
		string1[0] = '\0';
	}
	if (!string1 || !string2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(string1) + ft_strlen(string2)) + 1));
	if (!str)
		return (NULL);
	x = 0;
	i = -1;
	if (string1)
		while (string1[++i] != '\0')
			str[i] = string1[i];
	while (string2[x] != '\0')
		str[i++] = string2[x++];
	str[ft_strlen(string1) + ft_strlen(string2)] = '\0';
	free(string1);
	return (str);
}
