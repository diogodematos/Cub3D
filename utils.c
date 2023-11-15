/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:19:37 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/15 17:22:35 by dcarrilh         ###   ########.fr       */
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

int	redcol2(char *str)
{
	int	j;

	j = 0;
	if ((str[j] == 50) && ((str[j + 1] == 53)
			&& (str[j + 2] < 48 || str[j + 2] > 53))) 
		return (printf("Error1: Wrong Colors\n"), 1);
	if ((str[j] == 50) && ((str[j + 1] < 48 || str[j + 1] > 53)
			|| (str[j + 2] < 48 || str[j + 2] > 57))) 
		return (printf("Error2: Wrong Colors\n"), 1);
	if ((str[j] < 48 || str[j] > 50) || (str[j + 1] < 48
			|| str[j + 1] > 57) || (str[j + 2] < 48 || str[j + 2] > 57))
		return (printf("Error3: Wrong Colors\n"), 1);
	return (0);
}

int	redcol(char *str, int n)
{
	int	j;

	j = 0;
	if (n == 3)
	{
		if (redcol2(str) == 1)
			return (1);
	}
	else if (n == 2)
	{
		if ((str[j] < 48 || str[j] > 57)
			|| (str[j + 1] < 48 || str[j + 1] > 57))
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

int	redcheck_map(t_check *check, t_cub *cub, int i, int j)
{
	if (!ft_strchr(" 10WESN\n", cub->t_map[i][j]))
		return (printf("i: %i\nError: Inavid Character\n", i));
	if (cub->t_map[i][j] == 49 && cub->t_map[i][j + 1] && check->wall == 0)
		check->wall = 1;
	else if (cub->t_map[i][j] == 49 && (cub->t_map[i][j + 1] == 32
		|| cub->t_map[i][j + 1] == '\n') && check->wall == 1)
		check->wall = 0;
	else if ((cub->t_map[i][j] == 32 || cub->t_map[i][j] == 9)
		&& cub->t_map[i][j + 1] == 48)
		return (printf("error: map is open\n"), 1);
	else if (cub->t_map[i][j] == 48 && (cub->t_map[i + 1][j] == 32
		|| cub->t_map[i - 1][j] == 32))
		return (printf("error: map is open\n"), 1);
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
