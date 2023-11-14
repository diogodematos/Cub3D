/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:19:37 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/14 16:26:09 by dcarrilh         ###   ########.fr       */
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

int	redcol(char *str, int	n)
{
	int	j;

	j = 0;
	if (n == 3)
	{
		if ((str[j] == 50) && ((str[j + 1] == 53) && (str[j + 2] < 48 || str[j + 2] > 53))) 
			return (printf("Error1: Wrong Colors\n"), 1);
		if ((str[j] == 50) && ((str[j + 1] < 48 || str[j + 1] > 53) || (str[j + 2] < 48 || str[j + 2] > 57))) 
			return (printf("Error2: Wrong Colors\n"), 1);
		if ((str[j] < 48 || str[j] > 50) || (str[j + 1] < 48 || str[j + 1] > 57) || (str[j + 2] < 48 || str[j + 2] > 57))
			return (printf("Error3: Wrong Colors\n"), 1);
	}
	else if (n == 2)
	{
		if ((str[j] < 48 || str[j] > 57) || (str[j + 1] < 48 || str[j + 1] > 57))
			return (printf("Error2: Wrong Colors\n"), 1);
	}
	else if (n == 1)
	{
		if (str[j] < 48 || str[j] > 57)
			return (printf("Error3: Wrong Colors\n"), 1);					
	}
	else
		return (printf("Error: many numbers\n"), 1);
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


