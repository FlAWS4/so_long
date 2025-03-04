/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:56:09 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/04 17:21:35 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main()
{
	int c = '\n';
	printf("%d\n", ft_isprint(c));
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", ft_isascii(c));
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", ft_isdigit(c));
}*/