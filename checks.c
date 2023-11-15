/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:20 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/15 15:59:19 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_map(t_cub *cub, char **argv)
{
	char				*line;
	static int			i;
	int					fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: File don't exist\n");
		return ((void)close(fd));
	}
	get_height(cub, argv);
	cub->map = ft_calloc(sizeof(char *), cub->height + 1);
	if (!cub->map)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cub->map[i] = strdup(line);
		i++;
		free(line);
	}
	close(fd);
}

void	get_height(t_cub *cub, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cub->height++;
		free(line);
	}
	close(fd);
}

int	check_map(t_cub *cub, t_check *check, int j)
{
	static int	i;

	while (cub->t_map[i])
	{
		j = 0;
		while (cub->t_map[i][j] == 32 && cub->t_map[i][j] != '\n')
			j++;
		if (cub->t_map[i][j] == '\n')
		{
			i++;
			continue ;
		}
		if (cub->t_map[i][j] != 49)
			return (printf("i: %i\nError: Map don't start walls\n", i));
		while (cub->t_map[i][j])
		{
			if (redcheck_map(check, cub, i, j))
				return (1);
			j++;
		}
		if (check->wall == 1)
			return (printf("Error: map isn't close"));
		i++;
	}
	return (0);
}

int	check_player(t_cub *cub, t_check *check)
{
	static int	i;
	int			j;

	while (cub->t_map[i])
	{
		j = -1;
		while (cub->t_map[i][++j])
		{
			if (cub->t_map[i][j] == 'N' || cub->t_map[i][j] == 'S'
				|| cub->t_map[i][j] == 'E' || cub->t_map[i][j] == 'W')
			{
				if (!check->player)
				{
					cub->py = i;
					cub->px = j;
					check->player = 1;
				}
				else
					return (printf("error: many players\n"), 1);
			}
		}
		i++;
	}
	return (0);
}

int	checks(t_cub *cub, t_check *check, char **argv)
{
	static int	m;
	static int	i;

	get_map(cub, argv);
	if (check_identifier(cub, check, 0, 0) == 1)
		return (1);
	m = cub->height - cub->t_height;
	printf("m: %d\n", m);
	cub->t_map = ft_calloc((cub->t_height + 1), sizeof(char *));
	while (cub->map[m])
	{
		cub->t_map[i++] = strdup(cub->map[m++]);
	}
	if (check_player(cub, check) || check_map(cub, check, 0))
		return (1);
	return (0);
}
