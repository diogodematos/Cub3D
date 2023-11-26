/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/24 14:37:28 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define W 119
# define S 115
# define D 100
# define A 97
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include "cub.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}				t_image;

typedef struct s_f_c
{
	unsigned int	floor;
	unsigned int	ceiling;
}				t_f_c;

typedef struct s_rayCast
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	olddir_x;
	double	oldplane_x;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		drawstart;
	int		drawend;
	int		color;
	double	wall_x;
	t_image	*tex;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
}				t_rayCast;

typedef struct s_main
{
	void		*mlx;
	void		*mlx_win;
	int			map_width;
	int			map_height;
	int			wr;
	int			sr;
	int			ar;
	int			dr;
	int			rightr;
	int			leftr;
	char		**world_map;
	char		**paths;
	char		**map;
	t_rayCast	*raycast;
	t_image		*img;
	t_image		*tex;
	t_image		*n_tex;
	t_image		*s_tex;
	t_image		*w_tex;
	t_image		*e_tex;
	t_f_c		*f_c;
}				t_main;

int		game(t_cub *cub);

// Initialization

void	ft_initvar(t_main *main, t_cub *cub);

// RayCasting

void	ray_first_steps(t_main *main, int x);

void	ray_seconds_steps(t_main *main);

// MLX

void	my_mlx_pixel_put(t_image *imagem, int x, int y, int color);

// TEX

void	get_wall_x(t_main *main);

void	ft_tex_projection_x(t_main *main);

void	ft_tex_projection_y(t_main *main);

void	ray_casting(t_main *main);

void	ft_events(t_main *main);

void	initialize_mlx(t_main *main);

void	ft_move_forward(t_main *main);

void	ft_move_backwards(t_main *main);

void	ft_move_left(t_main *main);

void	ft_move_right(t_main *main);

void	ft_rotate_right(t_main *main);

void	ft_rotate_left(t_main *main);

void	new_image(t_main *main);

//		UTILS

void	ft_allocate_matrix(t_main *main);

void	ft_matrix_copy(char **world_map, t_main *min, t_cub *cub);

int		close_window(t_main *main);

void	ft_free(void *content);

void	destroy_img(t_main *main, t_image *img);

#endif
