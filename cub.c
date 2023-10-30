/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:31:22 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/30 14:41:27 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_cub(char **argv)
{
	int i;
	int	j;
	char	*str;

	i = ft_strlen(argv[1]);
	printf("i:%i\n", i);
	j = i - 5;
	printf("j:%i\n", j);
	str = ".cub";
	while (++j <= i )
	{
		if (argv[1][j] != *str++)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return(printf("%s\n","Error: Invalid numbers of arguments"));
	if (ft_check_cub(argv) == 1)
		return(printf("%s\n","Error: Invalid file extension"));
	return (0);
}