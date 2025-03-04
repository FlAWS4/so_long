/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:20:51 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:25:14 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (len);
}
/*#include <bsd/string.h>

int main(void)
{
	char src[] = "hello";
	char dest[] = "wrold";
	printf("%zu %s\n", ft_strlcpy(dest, src, 100), dest);
	printf("%zu %s\n", strlcpy(dest, src, 100), dest);
}//compile (-lbsd);*/
