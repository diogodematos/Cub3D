/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:41 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/24 14:39:11 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *imagem, int x, int y, int color)
{
	char	*dst;

	dst = imagem->addr + (y * imagem->line_length + x
			* (imagem->bpp / 8));
	*(unsigned int *)dst = color;
}

void	get_xpm_image(t_main *main, t_image *img, int x)
{
	img->img = mlx_xpm_file_to_image(main->mlx, main->paths[x],
			&img->w, &img->h);
	if (img->img == NULL)
		return ;
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}

void	initialize_mlx(t_main *main)
{
	main->mlx = mlx_init();
	main->mlx_win = mlx_new_window(main->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	main->img->img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img,
			&main->img->bpp, &main->img->line_length,
			&main->img->endian);
	get_xpm_image(main, main->n_tex, 0);
	get_xpm_image(main, main->s_tex, 1);
	get_xpm_image(main, main->e_tex, 2);
	get_xpm_image(main, main->w_tex, 3);
	if (main->n_tex->img == NULL || main->s_tex->img == NULL
		|| main->e_tex->img == NULL || main->w_tex->img == NULL)
	{
		printf("Error: No Texture\n");
		close_window(main);
		exit (1);
	}
}

void	new_image(t_main *main)
{
	main->img->img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	main->img->addr = mlx_get_data_addr(main->img->img,
			&main->img->bpp, &main->img->line_length,
			&main->img->endian);
}
