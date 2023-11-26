/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:01:26 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/24 11:39:20 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cub3d.h"

char	*replace(char *str, char a, char b)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == a)
			str[i] = b;
	}
	return (str);
}

char	*fillline(char *dest, char *src, t_cub *cub)
{
	int	i;

	i = -1;
	while (src[++i] && src[i] != '\n')
		dest[i] = src[i];
	while (i < cub->length)
		dest[i++] = 'X';
	return (dest);
}

void	ft_matrix_copy(char **world_map, t_main *main, t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->t_height)
	{
		ft_memcpy(main->world_map[i], world_map[i], ft_strlen(world_map[i]));
		i++;
	}
}

void	freetext(t_cub *cub)
{
	free(cub->ntext);
	free(cub->stext);
	free(cub->etext);
	free(cub->wtext);
}

void	ft_allocate_matrix(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	main->world_map = (char **)malloc(main->map_width * sizeof(char *));
	if (main->world_map == NULL)
		return ;
	while (i < main->map_width)
	{
		main->world_map[i] = (char *)malloc(main->map_height * sizeof(char));
		i++;
	}
}
