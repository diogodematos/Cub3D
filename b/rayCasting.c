/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:12:45 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/24 11:02:30 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_floor_and_ceiling(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	y = x;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < (SCREEN_HEIGHT / 2))
		{
			my_mlx_pixel_put(main->img, x, y, main->f_c->floor);
			y++;
		}
		while (y < (SCREEN_HEIGHT - 1))
		{
			my_mlx_pixel_put(main->img, x, y, main->f_c->ceiling);
			y++;
		}
		x++;
	}
}

int	ft_tex_color(t_main *main)
{
	int	color;

	color = *(unsigned int *)((main->tex->addr
				+ (main->raycast->tex_y * main->tex->line_length)
				+ (main->raycast->tex_x * main->tex->bpp / 8)));
	return (color);
}

void	ray_casting(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_floor_and_ceiling(main);
	while (x++ < SCREEN_WIDTH)
	{
		ray_first_steps(main, x);
		ray_seconds_steps(main);
		if (main->world_map[main->raycast->map_x][main->raycast->map_y] == '2')
			main->tex = main->d_tex;
		get_wall_x(main);
		ft_tex_projection_x(main);
		y = main->raycast->drawstart;
		while (y++ < main->raycast->drawend)
		{
			ft_tex_projection_y(main);
			if (x >= 0 && y >= 0 && main->raycast->tex_x >= 0
				&& main->raycast->tex_y >= 0)
			{
				main->raycast->color = ft_tex_color(main);
				my_mlx_pixel_put(main->img, x, y, main->raycast->color);
			}
		}
		//mlx_put_image_to_window(main->mlx, main->mlx_win, main->img->img, 0, 0);
	}
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->img->img, 0, 0);
	draw_minimap(main);
}
