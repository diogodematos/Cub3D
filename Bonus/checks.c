/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:20 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/20 17:04:13 by dcarrilh         ###   ########.fr       */
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
		cub->map[i++] = strdup(line);
		free(line);
	}
	if (i == 0)
		cub->mapa = 1;
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
		if (cub->length < (int)ft_strlen(line))
			cub->length = (int)ft_strlen(line);
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
		while (cub->t_map[i][j] == 32 || cub->t_map[i][j] == 'X')
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

int	check_player(t_cub *cub, t_check *check, int i)
{
	int			j;

	while (cub->t_map[++i])
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
					cub->player = cub->t_map[i][j];
				}
				else
					return (printf("error: many players\n"), 1);
			}
		}
	}
	if (!check->player)
		return (printf("error: no player\n"), 1);
	return (0);
}

int	checks(t_cub *cub, t_check *check, char **argv)
{
	static int	m;
	static int	i;

	get_map(cub, argv);
	if (cub->mapa == 1)
		return (myfree(cub->map), printf("Error: Empty .cub\n"), 1);
	if (check_identifier(cub, check, 0, 0) == 1)
		return (myfree(cub->map), printf("bad\n"), 1);
	m = cub->height - cub->t_height;
	printf("m: %d\n", m);
	cub->t_map = ft_calloc((cub->t_height + 1), sizeof(char *));
	while (cub->map[m])
	{
		cub->t_map[i] = ft_calloc(sizeof(char), cub->length + 1);
		cub->t_map[i] = fillline(cub->t_map[i], cub->map[m++], cub);
		cub->t_map[i] = replace(cub->t_map[i], ' ', 'X');
		cub->t_map[i][cub->length - 1] = '\n';    // length -> length -1
		cub->t_map[i][cub->length] = '\0';      // length +1 -> length
		printf("%s", cub->t_map[i++]);
	}
	if (check_player(cub, check, -1) || check_map(cub, check, 0))
		return (myfree(cub->t_map), myfree(cub->map), freetext(cub), 1);     // free text
	return (0);
}
