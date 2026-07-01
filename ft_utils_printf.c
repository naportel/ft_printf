/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naportel <naportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:49:06 by naportel          #+#    #+#             */
/*   Updated: 2025/11/06 13:56:13 by naportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_printchar(char c)
{
	int	count;

	count = write(1, &c, 1);
	return (count);
}

int	ft_len_printstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*s)
	{
		count += write(1, s, 1);
		s += 1;
	}
	return (count);
}

int	ft_len_printnbr(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648L)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_len_printnbr(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_len_printhex(unsigned int n, unsigned int base, char spec)
{
	int		count;
	char	*sym_l;
	char	*sym_u;

	sym_l = "0123456789abcdef";
	sym_u = "0123456789ABCDEF";
	count = 0;
	if ((n < base) && spec != 'X')
		count += ft_len_printchar(sym_l[n]);
	else if ((n < base) && spec == 'X')
		count += ft_len_printchar(sym_u[n]);
	else
	{
		count = ft_len_printhex(n / base, base, spec);
		return (count + ft_len_printhex(n % base, base, spec));
	}
	return (count);
}

int	ft_len_printptr(unsigned long long int ptr, int first_call)
{
	int	count;

	count = 0;
	if (ptr == 0 && first_call)
	{
		count += ft_len_printstr("(nil)");
		return (count);
	}
	if (first_call)
		count += ft_len_printstr("0x");
	if (ptr >= 16)
	{
		count += ft_len_printptr(ptr / 16, 0);
		count += ft_len_printptr(ptr % 16, 0);
	}
	else
	{
		if (ptr <= 9)
			count += ft_len_printchar(ptr + '0');
		else
			count += ft_len_printchar(ptr - 10 + 'a');
	}
	return (count);
}
