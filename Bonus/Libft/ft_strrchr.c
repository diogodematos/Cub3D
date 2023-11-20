/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:53:48 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/10/19 16:17:49 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int b)
{
	int			a;

	a = ft_strlen(str);
	while (b > 255)
		b = b - 256;
	if (b == '\0')
		return ((char *)str + a);
	while (a >= 0)
	{
		if (str[a] == b)
			return ((char *)str + a);
		a--;
	}
	return (0);
}

// int	main()
// {
// 	printf("%s\n", ft_strrchr("g",'\0'));
// 	printf("%s\n", strrchr("g",'\0'));
// 	//printf("%s\n", ft_strrchr("amanha",'f'));
// 	//printf("%s\n", strrchr("amanha",'f'));
// 	printf("%s\n", ft_strrchr("sgf+ghv",'+' + 256));
//         printf("%s\n", strrchr("sgf+ghv", '+' + 256));
// 	printf("%s\n", ft_strrchr("Aamanha",65));
//         printf("%s\n", strrchr("Aamanha",65));
// 	return (0);
// }
