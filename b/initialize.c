/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:35:02 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/24 11:00:57 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub.h"

void	ft_find_dir_e_w(t_main *main, char dir)
{
	if (dir == 'E')
	{
		main->raycast->dir_x = 1;
		main->raycast->dir_y = 0;
		main->raycast->plane_x = 0;
		main->raycast->plane_y = -0.66;
	}
	if (dir == 'W')
	{
		main->raycast->dir_x = -1;
		main->raycast->dir_y = 0;
		main->raycast->plane_x = 0;
		main->raycast->plane_y = 0.66;
	}
}

void	ft_find_direction(t_main *main, char dir)
{
	if (dir == 'N')
	{
		main->raycast->dir_x = 0;
		main->raycast->dir_y = -1;
		main->raycast->plane_x = -0.66;
		main->raycast->plane_y = 0;
	}
	if (dir == 'S')
	{
		main->raycast->dir_x = 0;
		main->raycast->dir_y = 1;
		main->raycast->plane_x = 0.66;
		main->raycast->plane_y = 0;
	}
	ft_find_dir_e_w(main, dir);
}

void	ft_tex(t_main *main, t_cub *cub)
{
	main->paths[0] = cub->ntext;
	main->paths[1] = cub->stext;
	main->paths[2] = cub->etext;
	main->paths[3] = cub->wtext;
	main->paths[4] = ft_strdup("textures/door.xpm");
}

void	ft_allocate_mem(t_main *main, t_cub *cub)
{
	main->raycast = malloc(sizeof(t_rayCast));
	main->img = malloc(sizeof(t_image));
	main->n_tex = malloc(sizeof(t_image));
	main->s_tex = malloc(sizeof(t_image));
	main->e_tex = malloc(sizeof(t_image));
	main->w_tex = malloc(sizeof(t_image));
	main->paths = malloc(5 * sizeof(char *));
	main->f_c = malloc(sizeof(t_f_c));
	main->map_width = cub->t_height;
	main->map_height = cub->length;
	ft_tex(main, cub);
	main->wr = 0;
	main->sr = 0;
	main->ar = 0;
	main->dr = 0;
	main->er = 0;
	main->rightr = 0;
	main->leftr = 0;
	main->d_tex = malloc(sizeof(t_image));
}

void	ft_initvar(t_main *main, t_cub *cub)
{
	ft_allocate_mem(main, cub);
	main->world_map = cub->t_map;
	main->raycast->pos_x = cub->py;
	main->raycast->pos_y = cub->px;
	ft_find_direction(main, cub->player);
	main->f_c->floor = cub->fcolor;
	main->f_c->ceiling = cub->ccolor;
	main->map = cub->map;
}
