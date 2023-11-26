/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:28:29 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/22 12:29:03 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_right(t_main *main)
{
	main->raycast->olddir_x = main->raycast->dir_x;
	main->raycast->dir_x = main->raycast->dir_x * cos(-0.02)
		- main->raycast->dir_y * sin(-0.02);
	main->raycast->dir_y = main->raycast->olddir_x * sin(-0.02)
		+ main->raycast->dir_y * cos(-0.02);
	main->raycast->oldplane_x = main->raycast->plane_x;
	main->raycast->plane_x = main->raycast->plane_x * cos(-0.02)
		- main->raycast->plane_y * sin(-0.02);
	main->raycast->plane_y = main->raycast->oldplane_x * sin(-0.02)
		+ main->raycast->plane_y * cos(-0.02);
}

void	ft_rotate_left(t_main *main)
{
	main->raycast->olddir_x = main->raycast->dir_x;
	main->raycast->dir_x = main->raycast->dir_x * cos(0.02)
		- main->raycast->dir_y * sin(0.02);
	main->raycast->dir_y = main->raycast->olddir_x * sin(0.02)
		+ main->raycast->dir_y * cos(0.02);
	main->raycast->oldplane_x = main->raycast->plane_x;
	main->raycast->plane_x = main->raycast->plane_x * cos(0.02)
		- main->raycast->plane_y * sin(0.02);
	main->raycast->plane_y = main->raycast->oldplane_x * sin(0.02)
		+ main->raycast->plane_y * cos(0.02);
}
