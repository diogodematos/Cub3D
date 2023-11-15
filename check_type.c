/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:44:29 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/15 12:07:41 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	color(t_check *check, char *s, int i, int j)
{
	if (!ft_strncmp(s, "C", 1) || !ft_strncmp(s, "F", 1))
	{
		while (s[i] == 32 || s[i] == 9)
			i++;
		if (s[i] == '\n')
			return (printf("error no color\n"), 1);
		while ((s[i] != 32 && s[i] != 9 && s[i] != '\n'))
		{
			j = i;
			while ((s[i] != ',' && check->comma != 2 && s[i]) || (s[i] != 32
					&& s[i] != '\n' && s[i] != 9 && check->comma == 2))
				i++;
			if (redcol(&s[j], (i - j)) == 1)
				return (1);
			if (s[i] == ',')
				check->comma += 1;
			if (s[i] == ',')
				i += 1;
		}
		while (s[i] == 32 || s[i] == 9)
			i++;
		if (s[i] != '\n' || s[i - 1] == ',')
			return (printf("many textures\n"), 1);
	}
	return (check->comma = 0, 0);
}

int	tex(char *str, int i)
{
	int		j;
	char	*text;

	j = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] == '\n')
		return (printf("error no texture\n"), 1);
	text = calloc(sizeof(char), 256);
	while (str[i] != 32 && str[i] != '\n' && str[i] != 9)
	{
		text[j++] = str[i];
		i++;
	}
	j = open(text, O_RDONLY);
	if (j == -1)
		return (printf("Error: Texture don't exist\n"), close(j), free(text), 1);
	close(j);
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] != '\n')
		return (free(text), printf("many textures\n"), 1);
	free(text);
	return (0);
}

int	type2(t_check *check, char *str)
{
	if (str[1] != 32 && str[1] != 9)
		return (printf("Error2: Wrong Type Identifier\n"));
	else if (!ft_strncmp(str, "F", 1) && (check->f == 0))
		check->f = 1;
	else if (!ft_strncmp(str, "C", 1) && (check->c == 0))
		check->c = 1;
	else
		return (printf("Error1: Double Type Identifier\n"));
	return (0);
}

int	type1(t_check *check, char *str)
{
	if (str[2] != 32 && str[2] != 9)
		return (printf("Error1: Wrong Type Identifier\n"));
	if (!ft_strncmp(str, "NO", 2) && (check->no == 0))
		check->no = 1;
	else if (!ft_strncmp(str, "SO", 2) && (check->so == 0))
		check->so = 1;
	else if (!ft_strncmp(str, "WE", 2) && (check->we == 0))
		check->we = 1;
	else if (!ft_strncmp(str, "EA", 2) && (check->ea == 0))
		check->ea = 1;
	else
		return (printf("Error2: Double Type Identifier\n"));
	return (0);
}

int	check_identifier(t_cub *cub, t_check *check, int i, int j)
{
	while (check->total < 6)
	{
		j = 0;
		while (cub->map[i][j] == 32 || cub->map[i][j] == 9)
			j++;
		if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
			|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
		{
			if (type1(check, &cub->map[i][j]) || tex(&cub->map[i][j], (j + 2)))
				return (1);
		}
		else if (cub->map[i][j] == 'C' || cub->map[i][j] == 'F')
		{
			if (type2(check, &cub->map[i][j])
				|| color(check, &cub->map[i][j], (j + 1), i))
				return (1);
		}
		else if (cub->map[i][0] == '\n')
			check->total--;
		else 
			return (printf("Error: Wrong Type Identifier\n"), 1);
		i++;
		check->total++;
	}
	return (cub->t_height = cub->height - i, 0);
}
