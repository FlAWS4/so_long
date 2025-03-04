/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:58:18 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:24:36 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof (char) * len + 1);
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
    char *src = "";
	char *src1 = ""; 
    char *dest;
	char *dest1;
    //int s_len,d_len;

    dest = ft_strdup(src);
	dest1 = strdup(src1);
    //s_len = ft_strlen(src);
    //d_len = ft_strlen(dest);

    printf("%s\n", dest1); 
    printf("%s", dest);
    return(0); 
}*/
