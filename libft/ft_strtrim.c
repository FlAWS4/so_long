/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:35:09 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:25:49 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	charset(const char *str, char c)
{
	while (*str && c != *str)
		str++;
	return (c == *str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (charset(set, s1[start]))
		start++;
	while (charset (set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
/*int	main()
{
	char	*str = "     **trimmed string   ****";
	char	*set = " *";
	printf("%s\n", ft_strtrim(str, set));
}
*/
