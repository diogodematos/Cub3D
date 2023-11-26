/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:44 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/22 11:59:49 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub.h"

int	moves(t_main *main)
{
	int	x;

	x = 0;
	x = main->wr + main->sr + main->ar + main->dr + main->rightr + main->leftr;
	if (main->wr == 1)
		ft_move_forward(main);
	if (main->sr == 1)
		ft_move_backwards(main);
	if (main->ar == 1)
		ft_move_left(main);
	if (main->dr == 1)
		ft_move_right(main);
	if (main->rightr == 1)
		ft_rotate_right(main);
	if (main->leftr == 1)
		ft_rotate_left(main);
	if (x > 0)
		return (1);
	return (0);
}

int	loop(t_main *main)
{
	int	control;

	control = moves(main);
	if (control == 0)
		return (0);
	else
	{
		mlx_destroy_image(main->mlx, main->img->img);
		new_image(main);
		ray_casting(main);
	}
	return (0);
}

int	game(t_cub *cub)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	ft_initvar(main, cub);
	initialize_mlx(main);
	ray_casting(main);
	ft_events(main);
	mlx_loop_hook(main->mlx, loop, main);
	mlx_loop(main->mlx);
	return (0);
}
