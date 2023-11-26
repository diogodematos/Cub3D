/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:37:53 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/24 11:55:45 by brolivei         ###   ########.fr       */
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

int		main(int argc, char **argv);
int		ft_check_cub(char **argv);

int		checks(t_cub *cub, t_check *check, char **argv);
void	get_map(t_cub *cub, char **argv);
void	get_height(t_cub	*cub, char **argv);

int		ft_strcmp(char *str, char *str2);
void	myfree(char **str);
int		redcol(char *str, int n);

int		check_identifier(t_cub *cub, t_check *check, int i, int j);

int		check_texture(char *type, char *str);
int		redux(int *i, int *j, t_check *check);
int		redcheck_map(t_check *check, t_cub *cub, int i, int j);
char	*replace(char *str, char a, char b);
char	*fillline(char *dest, char *src, t_cub *cub);
void	freetext(t_cub *cub);

int		check_player(t_cub *cub, t_check *check, int n);

#endif
