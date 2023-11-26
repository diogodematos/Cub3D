/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/22 12:28:54 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_forward(t_main *main)
{
	if (main->world_map[(int)(main->raycast->pos_x
			+ main->raycast->dir_x * 0.02)]
		[(int)(main->raycast->pos_y)] != '1')
	{
		main->raycast->pos_x += main->raycast->dir_x * 0.01;
	}
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y + main->raycast->dir_y * 0.02)] != '1')
	{
		main->raycast->pos_y += main->raycast->dir_y * 0.01;
	}
}

void	ft_move_backwards(t_main *main)
{
	if (main->world_map[(int)(main->raycast->pos_x
			- main->raycast->dir_x * 0.02)]
		[(int)(main->raycast->pos_y)] != '1')
		main->raycast->pos_x -= main->raycast->dir_x * 0.01;
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y - main->raycast->dir_y * 0.02)] != '1')
		main->raycast->pos_y -= main->raycast->dir_y * 0.01;
}

void	ft_move_left(t_main *main)
{
	double	perpendicular_x;
	double	perpendicular_y;
	double	move_x;
	double	move_y;

	perpendicular_x = -main->raycast->dir_y;
	perpendicular_y = main->raycast->dir_x;
	move_x = perpendicular_x * 0.005;
	move_y = perpendicular_y * 0.005;
	if (main->world_map[(int)(main->raycast->pos_x + move_x)]
		[(int)(main->raycast->pos_y)] != '1')
		main->raycast->pos_x += move_x;
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y + move_y)] != '1')
		main->raycast->pos_y += move_y;
}

void	ft_move_right(t_main *main)
{
	double	perpendicular_x;
	double	perpendicular_y;
	double	move_x;
	double	move_y;

	perpendicular_x = -main->raycast->dir_y;
	perpendicular_y = main->raycast->dir_x;
	move_x = perpendicular_x * 0.005 * (-1);
	move_y = perpendicular_y * 0.005 * (-1);
	if (main->world_map[(int)(main->raycast->pos_x + move_x)]
		[(int)(main->raycast->pos_y)] != '1')
		main->raycast->pos_x += move_x;
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y + move_y)] != '1')
		main->raycast->pos_y += move_y;
}
