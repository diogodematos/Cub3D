/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:20 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/31 16:31:36 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_map(t_cub *cub, char **argv)
{
	char	*line;
	static int	i;
	int fd;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: File don't exist");
		return ((void)close(fd));
	}
	get_height(cub, argv);
	cub->map = malloc(sizeof(char *) * cub->height + 1);
	if (!cub->map)
		return ;
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		cub->map[i] = strdup(line);
		free(line);
		i++;
	}
	cub->map[i] = NULL;
	close(fd);
}

void	get_height(t_cub	*cub, char **argv)
{
	char *line;
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		cub->height++;
		free(line);
	}
	close(fd);
}

int	check_identifier(t_cub *cub, t_check *check)
{
	static int	i;
	int	j;
	char	**split;

	while (check->total < 6)
	{
		j = 0;
		split = ft_split(cub->map[i], ' ');
		if (!ft_strncmp(cub->map[i], "NO", 2))
		{
			if (check->no == 0)
			{
				check->no = 1;
				check->total++;
			}
			else
				return (printf("Error: Double Type Identifier"));
		}
		else if (!ft_strncmp(cub->map[i], "SO", 2))
		{
			if (check->so == 0)
			{
				check->so = 1;
				check->total++;
			}
			else
				return (printf("Error: Double Type Identifier"));
		}
		else if (!ft_strncmp(cub->map[i], "EA", 2))
		{
			if (check->ea == 0)
			{
				check->ea = 1;
				check->total++;
			}
			else
				return (printf("Error: Double Type Identifier"));
		}
		else if (!ft_strncmp(cub->map[i], "WE", 2))
		{
			if (check->we == 0)
			{
				check->we = 1;
				check->total++;
			}
			else
				return (printf("Error: Double Type Identifier"));
		}
		else if (!ft_strncmp(cub->map[i], "F", 1))
		{
			if (check->f == 0)
			{
				check->f = 1;
				check->total++;
			}
			else
				return (printf("Error: Double Type Identifier"));
		}
		else if (!ft_strncmp(cub->map[i], "C", 1))
		{
			if (check->c == 0)
			{
				check->c = 1;
				check->total++;
			}
			else
				return (printf("Error: Double Type Identifier"));
		}
		else if (cub->map[i][j] == '\n')
			j = 0;
		else
			return (printf("Error: Wrong Type Identifier"));
		while(split[j])
			free(split[j]);
		free(split);
		i++;
	}
	return (0);
}

int	checks(t_cub *cub, t_check *check, char **argv)
{
	get_map(cub, argv);
	check_identifier(cub, check);
	return(0);
}
	