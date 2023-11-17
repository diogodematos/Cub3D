/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:44:29 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/17 12:52:00 by dcarrilh         ###   ########.fr       */
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

int	tex(char *str, int i, char **s)
{
	int		j;
	char	*text;

	j = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] == '\n')
		return (printf("error no texture\n"), 1);
	text = ft_calloc(sizeof(char), 256);
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
	*s = ft_strdup(text);
	free(text);
	return (0);
}

void	get_hex_color(char *str, unsigned long *s, int i)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	r = ft_atoi(&str[i]);
	while (str[i] != 32 && str[i] != '\n' && str[i] != 9 && str[i] != ',')
		i++;
	g = ft_atoi(&str[++i]);
	while (str[i] != 32 && str[i] != '\n' && str[i] != 9 && str[i] != ',')
		i++;
	b = ft_atoi(&str[++i]);
	printf("r: %i\ng: %i\nb: %i\n", r, g, b);
	*s = ((r * 65536) + (g * 256) + b);
}

int	type2(t_check *check, char *str, t_cub *cub)
{
	if (str[1] != 32 && str[1] != 9)
		return (printf("Error2: Wrong Type Identifier\n"));
	else if (!ft_strncmp(str, "F", 1) && (check->f == 0))
	{
		check->f = 1;
		get_hex_color(str, &cub->fcolor, 1);
		printf("%lu\n", cub->fcolor);
	}
	else if (!ft_strncmp(str, "C", 1) && (check->c == 0))
	{
		check->c = 1;
		get_hex_color(str, &cub->ccolor, 1);
		printf("%lu\n", cub->ccolor);
	}
	else
		return (printf("Error1: Double Type Identifier\n"));
	return (0);
}

int	type1(t_check *check, t_cub *cub, int i, int j)
{
	if (cub->map[i][j + 2] != 32 && cub->map[i][j + 2] != 9)
		return (printf("Error1: Wrong Type Identifier\n"));
	if (!ft_strncmp(cub->map[i], "NO", 2) && (check->no == 0))
	{
		check->no = 1;
		tex(&cub->map[i][j], (j + 2), &cub->ntext);
	}
	else if (!ft_strncmp(cub->map[i], "SO", 2) && (check->so == 0))
	{
		check->so = 1;
		tex(&cub->map[i][j], (j + 2), &cub->stext);
	}
	else if (!ft_strncmp(cub->map[i], "WE", 2) && (check->we == 0))
	{
		check->we = 1;
		tex(&cub->map[i][j], (j + 2), &cub->wtext);
	}
	else if (!ft_strncmp(cub->map[i], "EA", 2) && (check->ea == 0))
	{
		check->ea = 1;
		tex(&cub->map[i][j], (j + 2), &cub->etext);
	}
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
			if (type1(check, cub, i, j))
				return (1);
		}
		else if (cub->map[i][j] == 'C' || cub->map[i][j] == 'F')
		{
			if (type2(check, &cub->map[i][j], cub)
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
