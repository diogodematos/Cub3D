/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:39:41 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/24 14:37:45 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (redcol(&s[j], (i - j)))
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

void	ft_free(void *content)
{
	if (!content)
		return ;
	free(content);
}

void	destroy_img(t_main *main, t_image *img)
{
	if (!img->img)
		return ;
	else
		mlx_destroy_image(main->mlx, img->img);
}
