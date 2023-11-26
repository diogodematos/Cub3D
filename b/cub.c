/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:31:22 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/22 14:34:59 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub3d.h"

int	ft_check_cub(char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(argv[1]);
	j = i - 5;
	if (!ft_strcmp(argv[1], ".cub"))
		return (printf("Error: only .cub\n"), 1);
	str = ".cub";
	while (++j <= i)
	{
		if (argv[1][j] != *str++)
			return (1);
	}
	return (0);
}

void	init_struct(t_cub *cub, t_check *check)
{
	ft_bzero(cub, sizeof(t_cub));
	ft_bzero(check, sizeof(t_check));
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	t_check	check;

	if (argc != 2)
		return (printf("Error: Invalid numbers of arguments\n"));
	if (ft_check_cub(argv))
		return (printf("Error: Invalid file extension\n"));
	init_struct(&cub, &check);
	if (checks(&cub, &check, argv))
		return (0);
	game(&cub);
	freetext(&cub);
	myfree(cub.map);
	myfree(cub.t_map);
	return (0);
}
