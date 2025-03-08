/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:04:28 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/06 22:04:29 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/libft.h"

void	ft_putstr(char *str, size_t *return_val)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, return_val);
		str++;
	}
}

static size_t	ft_len(size_t n, char *base)
{
	size_t				len;
	size_t				nb;

	len = 1;
	nb = ft_strlen(base);
	while (n >= nb)
	{
		n /= nb;
		len++;
	}
	return (len);
}

char	*ft_convertbase(size_t n, char *base)
{
	char	*str;
	int		len;
	int		nb;
	int		i;

	len = ft_len(n, base);
	nb = ft_strlen(base);
	str = malloc((len + 1) * sizeof(char));
	if (!str || !base)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		str[i] = '\0';
		i++;
	}
	while (len > 0)
	{
		len--;
		str[len] = base[n % nb];
		n /= nb;
	}
	return (str);
}
