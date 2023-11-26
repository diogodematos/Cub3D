/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:37:53 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/24 14:38:36 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../Libft/libft.h"
//# include "cub3d.h"

typedef struct check
{
	int	no;
	int	ea;
	int	we;
	int	so;
	int	f;
	int	c;
	int	total;
	int	wall;
	int	f_line;
	int	player;
	int	comma;
}	t_check;

typedef struct cub
{
	int				mapa;
	char			*ntext;
	char			*stext;
	char			*etext;
	char			*wtext;
	unsigned long	fcolor;
	unsigned long	ccolor;
	char			player;
	char			**map;
	char			**t_map;
	int				height;
	int				length;
	int				t_height;
	int				py;
	int				px;
}	t_cub;

// Init

int		main(int argc, char **argv);

void	init_struct(t_cub *cub, t_check *check);

// Checks

int		ft_check_cub(char **argv);

int		checks(t_cub *cub, t_check *check, char **argv);

int		check_map(t_cub *cub, t_check *check, int j);

int		check_identifier(t_cub *cub, t_check *check, int i, int j);

int		type1(t_check *check, t_cub *cub, int i, int j);

int		type2(t_check *check, char *str, t_cub *cub);

int		color(t_check *check, char *s, int i, int j);

// Get Map Values

int		get_map(t_cub *cub, char **argv);

void	get_height(t_cub	*cub, char **argv);

int		check_player(t_cub *cub, t_check *check, int i);

int		tex(char *str, int i, char **s);

void	get_hex_color(char *str, unsigned long *s, int i);

// Utils

int		ft_strcmp(char *str, char *str2);

char	*fillline(char *dest, char *src, t_cub *cub);

char	*replace(char *str, char a, char b);

// Line Reduction

int		redcol(char *str, int n);

int		redcol2(char *str);

int		redcheck_map(t_check *check, t_cub *cub, int i, int j);

// Clean

void	myfree(char **str);

void	freetext(t_cub *cub);

#endif
