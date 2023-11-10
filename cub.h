/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:37:53 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/10 15:49:54 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./Libft/libft.h"

typedef struct	check
{
	int	no;
	int ea;
	int	we;
	int	so;
	int	f;
	int	c;
	int	total;
	int	wall;
	int	f_line;
	int	player;
}	t_check;

typedef struct	cub
{
		char **map;
		char **t_map;
		int	height;
}	t_cub;


int	main(int argc, char **argv);
int	ft_check_cub(char **argv);

int	checks(t_cub *cub, t_check *check, char **argv);
void	get_map(t_cub *cub, char **argv);
void	get_height(t_cub	*cub, char **argv);

int	ft_strcmp(char *str, char *str2);
void	myfree(char **str);

int	check_texture(char *str);
int redux(int *i, int *j, t_check *check);

int	check_player(t_cub *cub, t_check *check);




#endif