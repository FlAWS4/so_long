/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:07:10 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/10 14:32:54 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)(s));
}

/*
int	main()
{
	char	*str = "can you find it";
	char    *str1 = "can you find it";
	char	*find = ft_strchr(str, '\0');
	char    *find1 = strchr(str1, '\0');
	printf("%p\n", find);
	printf("%p", find1);
}*/
