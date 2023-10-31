/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:02:05 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/31 12:00:48 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	a;

	if (!s)
		return (0);
	dest = malloc (len * sizeof (char) + 1);
	if (!dest)
		return (0);
	a = 0;
	if (ft_strlen(s) >= start)
	{
		while (s[start] && a != len)
		{
			dest[a] = s[start];
			a++;
			start++;
		}
	}
	dest[a] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*dest;
	unsigned int	a;
	unsigned int	b;

	if (!s1 || !s2)
		return (0);
	dest = ft_calloc (((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	a = 0;
	while (s1[a])
	{
		dest[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b])
	{
		dest[a] = s2[b];
		a++;
		b++;
	}
	return (dest);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	array;
	char	*ptr;
	size_t	i;

	array = num * size;
	ptr = malloc(array);
	if (!ptr)
		return (0);
	i = 0;
	while (array > 0)
	{
		ptr[i] = 0;
		i++;
		array--;
	}
	return ((void *)ptr);
}
