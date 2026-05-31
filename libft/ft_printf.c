/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:28:34 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_printf.c — Custom printf implementation
**
** ft_printf(s, ...):
**   วน loop ผ่านแต่ละ char ใน format string s
**   เจอ '%' → เรียก ft_check() เพื่อ handle specifier ถัดไป
**   ไม่ใช่ '%' → print ตรงๆ ด้วย ft_putchar()
**   คืนจำนวน characters ที่ print ทั้งหมด
**
** ft_check(args, c):
**   dispatcher สำหรับ specifier ตัวเดียว
**   %c, %s, %% → จัดการตรงนี้
**   %d/%i/%u/%x/%X/%p → ส่งต่อให้ ft_check_num()
**
** ft_check_num(args, c):
**   จัดการ specifiers ตัวเลข:
**   %d/%i → int, %u → unsigned, อื่นๆ → ft_check_hex()
**
** ft_check_hex(args, c):
**   จัดการ %x/%X/%p
*/

#include "ft_printf.h"

int	ft_check_hex(va_list *args, char c)
{
	char	*base;

	if (c == 'x')
	{
		base = "0123456789abcdef";
		return (ft_putnbr_base_len(va_arg(*args, unsigned int), base));
	}
	else if (c == 'X')
	{
		base = "0123456789ABCDEF";
		return (ft_putnbr_base_len(va_arg(*args, unsigned int), base));
	}
	else if (c == 'p')
		return (ft_putpointer(va_arg(*args, unsigned long long)));
	return (0);
}

int	ft_check_num(va_list *args, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base_len(va_arg(*args, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base_len(va_arg(*args, unsigned int), "0123456789"));
	return (ft_check_hex(args, c));
}

int	ft_check(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_check_num(args, c));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			length += ft_check(&args, s[i]);
		}
		else
			length += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}
