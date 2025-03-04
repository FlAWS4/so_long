/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:07:49 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:24:51 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc(sizeof(*str), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}
/*
int	main()
{
	char	str[] = "hello join";
	char 	sep[] = "with me";
	char	*res = ft_strjoin(str, sep);
	printf("%s", res);
}*/
