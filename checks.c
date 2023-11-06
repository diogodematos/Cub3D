/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:20 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/06 17:52:02 by dcarrilh         ###   ########.fr       */
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
		printf("Error: File don't exist");
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
	if (!ft_strcmp(str, "NO"))
	{
		if (check->no == 0)
			check->no = 1;
		else
			return (printf("Error: Double Type Identifier"));
	}
	else if (!ft_strcmp(str, "SO"))
	{
		if (check->so == 0)
			check->so = 1;
		else
			return (printf("Error: Double Type Identifier"));
	}
	else if (!ft_strcmp(str, "EA"))
	{
		if (check->ea == 0)
			check->ea = 1;
		else
			return (printf("Error: Double Type Identifier"));
	}
	return (0);
}

int check_identifier3(t_check *check, char *str)
{
	if (!ft_strcmp(str, "WE"))
	{
		if (check->we == 0)
			check->we = 1;
		else
			return (printf("Error: Double Type Identifier"));
	}
	else if (!ft_strcmp(str, "F"))
	{
		if (check->f == 0)
			check->f = 1;
		else
			return (printf("Error: Double Type Identifier"));
	}
	else if (!ft_strcmp(str, "C"))
	{
		if (check->c == 0)
			check->c = 1;
		else
			return (printf("Error: Double Type Identifier"));
	}
	return (0);
}
	

int check_identifier(t_cub *cub, t_check *check)
{
	static int i;
	char **split;

	while (check->total < 6)
	{
		split = ft_split((const char *)cub->map[i], ' ');
		if (split[2])
		{
			myfree(split);
			return (printf("Error: Many Type Identifier\n"));
		}
		if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO") || !ft_strcmp(split[0], "EA")
			|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		{	
			if (check_identifier2(check, split[0]) || check_identifier3(check, split[0]))
				return (myfree(split), 1);
		}
		else if (cub->map[i][0] == '\n')
			check->total--;
		else 
		{
			myfree(split);
			return (printf("Error: Wrong Type Identifier"));
		}
		myfree(split);
		check->total++;
		i++;
	}
	return (0);
}

int checks(t_cub *cub, t_check *check, char **argv)
{	
	get_map(cub, argv);
	check_identifier(cub, check);
	return (0);
}
