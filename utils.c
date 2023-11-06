/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:19:37 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/06 17:52:10 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		else
			i++;
	}
	if (str[i] != str2[i])
			return (str[i] - str2[i]);
	return (0);
}

void	myfree(char **str)
{
	int	i;
	
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

