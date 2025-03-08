/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:53:55 by mshariar          #+#    #+#             */
/*   Updated: 2025/03/06 21:53:56 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libft.h"
#include <stdarg.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

void	ft_putuint(unsigned int num, size_t *return_val)
{
	char	*str;

	str = ft_convertbase(num, "0123456789");
	ft_putstr(str, return_val);
	free(str);
}


void	ft_puthex(unsigned int num, size_t *return_val, char *base)
{
	char	*str;

	str = ft_convertbase(num, base);
	ft_putstr(str, return_val);
	free(str);
}
void	ft_putptr(void *ptr, size_t *return_val)
{
	char			*str;
	unsigned long	ptr_address;

	if (!ptr)
	{
		ft_putstr("(nil)", return_val);
		return ;
	}
	ptr_address = (unsigned long)ptr;
	ft_putstr("0x", return_val);
	str = ft_convertbase(ptr_address, HEX_LOW_BASE);
	ft_putstr(str, return_val);
	free(str);
}


void	ft_putnbr(int n, size_t *return_val)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', return_val);
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10, return_val);
	ft_putchar((nb % 10 + '0'), return_val);
}

int	ft_putchar(char c, size_t *return_val)
{
	int	error;

	error = write(1, &c, 1);
	if (error == -1)
		return (-1);
	(*return_val)++;
	return (0);
}

int	ft_format(va_list ap, char *str, size_t *return_val)
{
	if (*str == 'c')
		ft_putchar(va_arg(ap, int), return_val);
	else if (*str == 's')
		ft_putstr(va_arg(ap, char *), return_val);
	else if (*str == 'p')
		ft_putptr(va_arg(ap, void *), return_val);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr(va_arg(ap, int), return_val);
	else if (*str == 'u')
		ft_putuint(va_arg(ap, unsigned int), return_val);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex(va_arg(ap, unsigned int), return_val, HEX_LOW_BASE);
		else
			ft_puthex(va_arg(ap, unsigned int), return_val, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_putchar(*str, return_val);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	size_t		return_val;

	if (!str)
		return (-1);
	return_val = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(ap, (char *)str, &return_val);
		}
		else
		{
			ft_putchar(*str, &return_val);
		}
		str++;
	}
	va_end(ap);
	return (return_val);
}
