/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:04:15 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/06 22:04:16 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i += 1;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
			dest[i++] = '\0';
	}
	dest[i] = '\0';
	return (dest);
}

char	*trim_free(char *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
		beg += 1;
	end = ft_strlen(s1 + beg);
	while (end > beg && ft_strchr(set, s1[(beg + end) - 1]) != NULL)
		end -= 1;
	trimmed_str = malloc((end + 1) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strncpy(trimmed_str, (s1 + beg), end);
	free(s1);
	return (trimmed_str);
}
