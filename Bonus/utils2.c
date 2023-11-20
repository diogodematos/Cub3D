/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:01:26 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/20 14:17:18 by dcarrilh         ###   ########.fr       */
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

char	*fillline(char *dest, char *src, t_cub *cub)
{
	int i;
	
	i = -1;
	while (src[++i] && src[i] != '\n') // don't read new line
		dest[i] = src[i];
	while (i < cub->length)  // copia ate ao final
		dest[i++] = 'X';
	return (dest);
}