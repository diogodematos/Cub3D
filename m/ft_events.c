/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:30:54 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/24 14:38:04 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(t_main *main)
{
	int	x;

	x = 0;
	if (main->world_map == NULL)
		return ;
	while (x < main->map_width)
	{
		free(main->world_map[x]);
		x++;
	}
	free(main->world_map);
}

int	close_window(t_main *main)
{
	destroy_img(main, main->img);
	destroy_img(main, main->n_tex);
	destroy_img(main, main->s_tex);
	destroy_img(main, main->e_tex);
	destroy_img(main, main->w_tex);
	mlx_destroy_window(main->mlx, main->mlx_win);
	mlx_destroy_display(main->mlx);
	free_matrix(main);
	ft_free(main->n_tex);
	ft_free(main->s_tex);
	ft_free(main->e_tex);
	ft_free(main->w_tex);
	ft_free(main->paths[0]);
	ft_free(main->paths[1]);
	ft_free(main->paths[2]);
	ft_free(main->paths[3]);
	ft_free(main->paths);
	ft_free(main->img);
	ft_free(main->mlx);
	ft_free(main->raycast);
	ft_free(main->f_c);
	myfree(main->map);
	ft_free(main);
	exit(0);
	return (0);
}

int	release_key(int keycode, t_main *main)
{
	if (keycode == W)
		main->wr = 0;
	if (keycode == S)
		main->sr = 0;
	if (keycode == A)
		main->ar = 0;
	if (keycode == D)
		main->dr = 0;
	if (keycode == RIGHT)
		main->rightr = 0;
	if (keycode == LEFT)
		main->leftr = 0;
	return (0);
}

int	movement(int keycode, t_main *main)
{
	if (keycode == W)
		main->wr = 1;
	if (keycode == S)
		main->sr = 1;
	if (keycode == A)
		main->ar = 1;
	if (keycode == D)
		main->dr = 1;
	if (keycode == RIGHT)
		main->rightr = 1;
	if (keycode == LEFT)
		main->leftr = 1;
	if (keycode == ESC)
		close_window(main);
	return (0);
}

void	ft_events(t_main *main)
{
	mlx_hook(main->mlx_win, 17, 0, close_window, main);
	mlx_hook(main->mlx_win, KeyPress, KeyPressMask, movement, main);
	mlx_hook(main->mlx_win, KeyRelease, KeyReleaseMask, release_key, main);
}
