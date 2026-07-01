/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naportel <naportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:05:46 by naportel          #+#    #+#             */
/*   Updated: 2025/12/01 15:06:08 by naportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	var_printer(va_list ap, char spec)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_len_printchar(va_arg(ap, int));
	else if (spec == 's')
		count += ft_len_printstr(va_arg(ap, char *));
	else if (spec == 'p')
		count += ft_len_printptr(va_arg(ap, unsigned long long int), 1);
	else if (spec == 'd' || spec == 'i')
		count += ft_len_printnbr(va_arg(ap, int));
	else if (spec == 'u')
		count += ft_len_printhex(va_arg(ap, unsigned int), 10, spec);
	else if (spec == 'x' || spec == 'X')
		count += ft_len_printhex(va_arg(ap, unsigned int), 16, spec);
	else if (spec == '%')
		count += ft_len_printchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += var_printer(ap, *(format + 1));
			format += 2;
		}
		else
		{
			count += write(1, format, 1);
			format += 1;
		}
	}
	va_end(ap);
	return (count);
}

/*#include <stdio.h>

int main(void)
{
    int num = 42;
    char c = 'h';
    char *str = "Man in the Mirror";
    void *ptr = &num;

    ft_printf("Test %%d: %d\n", num);
    ft_printf("Test %%i: %i\n", -12345);

    ft_printf("Test %%s: %s\n", str);
    ft_printf("Test %%s with NULL: %s\n", (char *)NULL);

    ft_printf("Test %%c: %c\n", c);

    ft_printf("Test %%: %%\n");

    ft_printf("Test %%p: %p\n", ptr);
    ft_printf("Test %%p with NULL: %p\n", NULL);

    ft_printf("Mixed: c=%c, s=%s, d=%d, p=%p, %%=%%\n", c, str, num, ptr);

	ft_printf(0);
	printf(0);
    return 0;
}
*/
