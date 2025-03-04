/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:42:22 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:23:09 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*p;

	p = (const char *)s;
	i = -1;
	while (++i < n)
	{
		if ((char)*(p + i) == (char)c)
			return ((void *)(p + i));
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "copy that";
	char	*res = ft_memchr(str, ' ', 5);
	char	*str1 = "copy that";
	char	*res1 = ft_memchr(str1, ' ', 5);

	printf("%s\n", res);
	printf("%s", res1);
}*/