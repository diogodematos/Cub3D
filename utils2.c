/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:01:26 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/20 12:23:09 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char *replace(char *str, char a, char b)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == a)
			str[i] = b;
	}
	return (str);
}

char	*fillline(char *dest, char *src)
{
	int i;
	
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	while (dest[i])
		dest[i++] = 'X';
	return (dest);
}