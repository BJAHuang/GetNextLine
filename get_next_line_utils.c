/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahuang <ahuang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/21 15:59:23 by ahuang        #+#    #+#                 */
/*   Updated: 2022/09/09 11:49:58 by someone       ########   odam.nl         */
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

char	*ft_strchr(char *str_1, int c)
{
	int	str_2;

	str_2 = 0;
	if (!str_1)
		return (0);
	if (c == '\0')
		return ((char *)&str_1[ft_strlen(str_1)]);
	while (str_1[str_2] != '\0')
	{
		if (str_1[str_2] == (char) c)
			return ((char *)&str_1[str_2]);
		str_2++;
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

// This version does not use memcpy anymore -> see older version for memcpy
// void	*ft_memcpy(void *destination, const void *source, size_t n)
// {
// 	char	*final_dst;
// 	char	*start_src;

// 	size_t = i;
// 	final_dst = (char *)destination;
// 	start_src = (char *)source;
// 	i = 0;
// 	if ((final_dst != NULL) && (start_src != NULL))
// 	{
// 		while (i < n)
// 		{
// 			final_dst[i] = start_src[i];
// 			i++;
// 		}
// 	}
// 	return (destination);
// }
