/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:31:22 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/02 13:41:01 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_cub(char **argv)
{
	int i;
	int	j;
	char	*str;

	i = ft_strlen(argv[1]);
	j = i - 5;
	str = ".cub";
	while (++j <= i )
	{
		if (argv[1][j] != *str++)
			return (1);
	}
	return (0);
}

void	init_struct(t_cub *cub, t_check *check)
{
	ft_bzero(cub, sizeof(t_cub));
	ft_bzero(check, sizeof(t_check));
}



int	main(int argc, char **argv)
{
	t_cub	cub;
	t_check	check;
	
	if (argc != 2)
		return(printf("%s\n","Error: Invalid numbers of arguments"));
	if (ft_check_cub(argv) == 1)
		return(printf("%s\n","Error: Invalid file extension"));
	init_struct(&cub, &check);
	checks(&cub, &check, argv);
	printf("height: %d\n", cub.height);
	printf("%s", cub.map[2]);
	return (0);
}