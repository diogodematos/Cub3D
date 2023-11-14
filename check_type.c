/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:44:29 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/14 16:20:32 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_color(t_check *check, char *str, int i, int j)
{
	if (!ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "F ", 2))
	{
		while (str[i] == 32 || str[i] == 9)
			i++;
		if (str[i] == '\n')
			return (printf("error no color\n"), 1);
		while((str[i] != 32 && str[i] != 9 && str[i] != '\n'))
		{
			j = i;
			while ((str[i] != ',' && check->comma != 2) || (str[i] != 32 && str[i] != '\n' && str[i] != 9 && check->comma == 2))
				i++;
			if (redcol(&str[j], (i - j)) == 1)
				return (1);
			if (str[i] == ',')
				check->comma += 1;
			if (str[i] == ',')
				i += 1;
		}	
		while (str[i] == 32 || str[i] == 9)
			i++;
		if (str[i] != '\n' || str[i - 1] == ',')
			return (printf("many textures\n"), 1);
	}
	check->comma = 0;
	return (0);
}


// int	check_color(char *type, char *str)
// {
// 	int	i;
// 	int comma;
// 	int n;

// 	i = 0;
// 	n = 0;
// 	comma = 0;
// 	if (!ft_strncmp(type, "C ", 2) || !ft_strncmp(type, "F ", 2))
// 	{
// 		while (str[i] == 32 || str[i] == 9)
// 			i++;
// 		while(str[i] != 32 && str[i] != 9 && str[i] != '\n')
// 		{
// 			if (i == 0 || str[i - 1] == 32 || str[i - 1] == 9 || str[i - 1] == ',')
// 			{
// 				if (str[i] < 48 || str[i] > 50) 
// 					return (printf("Error1: Wrong Colors\n"), 1);
// 				n += 1;
// 			}
// 			else if (str[i] == ';' && n < 4)
// 				comma += 1;
// 			else if (str[i] == ';' && n > 3)
// 				return (printf("Error2: Wrong Colors\n"), 1);
// 			else
// 			{
// 				if (str[i] < 48 || str[i] > 55)
// 					return (printf("Error3: Wrong Colors\n"), 1);
// 				n += 1;
// 			}
// 			i++;
// 		}
// 		if (comma > 2)
// 			return (printf("Error: Many Commas\n"));
// 		while (str[i] == 32)
// 			i++;
// 		if (str[i] != '\n')
// 			return (printf("many textures\n"), 1);
// 	}
// 	return (0);
// }

int	check_texture(char *type, char *str)
{
	int i;
	int	j;
	char	*text;
	
	i = 0;
	j = 0;
	if (!ft_strncmp(type, "NO ", 3) || !ft_strncmp(type, "SO ", 3) || !ft_strncmp(type, "EA ", 3)
			|| !ft_strncmp(type, "WE ", 3))
	{	
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
		{
			printf("Error: Texture don't exist\n");
			return (close(j),free(text), 1);
		}
		close(j);
		while (str[i] == 32 || str[i] == 9)
			i++;
		if (str[i] != '\n')
			return (free(text), printf("many textures\n"), 1);
		free(text);
	}
	return (0);
}

int check_identifier3(t_check *check, char *str)
{
	if (!ft_strncmp(str, "WE ", 3))
	{
		if (check->we == 0)
			check->we = 1;
		else
			return (printf("Error: Double Type Identifier\n"));
	}
	else if (!ft_strncmp(str, "F ", 2))
	{
		if (check->f == 0)
			check->f = 1;
		else
			return (printf("Error: Double Type Identifier\n"));
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		if (check->c == 0)
			check->c = 1;
		else
			return (printf("Error: Double Type Identifier\n"));
	}
	return (0);
}

int check_identifier2(t_check *check, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (check->no == 0)
			check->no = 1;
		else
			return (printf("Error: Double Type Identifier\n"));
	}
	else if (!ft_strncmp(str, "SO ", 3))
	{
		if (check->so == 0)
			check->so = 1;
		else
			return (printf("Error: Double Type Identifier\n"));
	}
	else if (!ft_strncmp(str, "EA ", 3))
	{
		if (check->ea == 0)
			check->ea = 1;
		else
			return (printf("Error: Double Type Identifier\n"));
	}
	return (0);
}

int check_identifier(t_cub *cub, t_check *check)
{
	static int i;
	static int	j;

	while (check->total < 6)
	{
		while (cub->map[i][j] == 32 || cub->map[i][j] == 9)
			j++;
		if (!ft_strncmp(&cub->map[i][j], "NO ", 3) || !ft_strncmp(&cub->map[i][j], "SO ", 3) || !ft_strncmp(&cub->map[i][j], "EA ", 3)
			|| !ft_strncmp(&cub->map[i][j], "WE ", 3) || !ft_strncmp(&cub->map[i][j], "F ", 2) || !ft_strncmp(&cub->map[i][j], "C ", 2))
		{	
			if (check_identifier2(check, &cub->map[i][j]) || check_identifier3(check, &cub->map[i][j]) || (check_texture(&cub->map[i][j], &cub->map[i][j + 3]) == 1)
				|| (check_color(check, &cub->map[i][j], (j + 2), i) == 1))
				return (1);
		}
		
		else if (cub->map[i][0] == '\n')
			check->total--;
		else 
			return (printf("Error: Wrong Type Identifier\n"), 1);
		i++;
		j = 0;
		check->total++;
	}
	return (i - 1);
}
