/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:53:44 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:23:22 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main() 
{ 
	char csrc[] = GeeksforGeeks";
	char cdest[10];
	char src[] = "GeeksforGeeks";
	char dest[10];

	memcpy(dest, src, 0);
	ft_memcpy(cdest, csrc, 0); 
	printf("%s\n", cdest);
	printf("%s", dest);	
	return (0);
}*/
