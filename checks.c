/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:20 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/09 13:04:01 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void get_map(t_cub *cub, char **argv)
{
	char *line;
	static int i;
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: File don't exist\n");
		return ((void)close(fd));
	}
	get_height(cub, argv);
	cub->map = ft_calloc(sizeof(char *), cub->height + 1);
	if (!cub->map)
		return;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		cub->map[i] = strdup(line);
		i++;
		free(line);
	}
	close(fd);
}

void get_height(t_cub *cub, char **argv)
{
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		cub->height++;
		free(line);
	}
	close(fd);
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
	
int	check_texture(char *str)
{
	int i;
	
	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '\n')
		return (printf("error no texture\n"), 1);
	while (str[i] != 32 && str[i] != '\n')
		i++;
	while (str[i] == 32)
		i++;
	if (str[i] != '\n')
		return (printf("many textures\n"), 1);
	return (0);
}

int check_identifier(t_cub *cub, t_check *check)
{
	static int i;
	static int	j;

	while (check->total < 6)
	{
		while (cub->map[i][j] == 32)
			j++;
		if (!ft_strncmp(&cub->map[i][j], "NO ", 3) || !ft_strncmp(&cub->map[i][j], "SO ", 3) || !ft_strncmp(&cub->map[i][j], "EA ", 3)
			|| !ft_strncmp(&cub->map[i][j], "WE ", 3) || !ft_strncmp(&cub->map[i][j], "F ", 2) || !ft_strncmp(&cub->map[i][j], "C ", 2))
		{	
			if (check_identifier2(check, &cub->map[i][j]) || check_identifier3(check, &cub->map[i][j]))
				return (1);
			else
			{
				if (check_texture(&cub->map[i][j + 3]) == 1)
					return (1);
			}
		}
		else if (cub->map[i][0] == '\n')
			check->total--;
		else 
			return (printf("Error: Wrong Type Identifier\n"), 1);
		redux(&i, &j, check);
	}
	return (0);
}

int checks(t_cub *cub, t_check *check, char **argv)
{	
	get_map(cub, argv);
	if (check_identifier(cub, check))
		return (1);
	return (0);
}
