/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naportel <naportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:28:06 by naportel          #+#    #+#             */
/*   Updated: 2025/11/06 13:54:45 by naportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	var_printer(va_list ap, char spec);
int	ft_len_printchar(char c);
int	ft_len_printstr(char *s);
int	ft_len_printnbr(long n);
int	ft_len_printhex(unsigned int n, unsigned int base, char spec);
int	ft_len_printptr(unsigned long long int ptr, int first_call);

#endif
