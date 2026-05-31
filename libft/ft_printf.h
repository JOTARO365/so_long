/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:28:53 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_printf.h — Header สำหรับ ft_printf ที่รวมอยู่ใน libft
**
** Specifiers ที่รองรับ:
**   %c  → character
**   %s  → string (NULL → "(null)")
**   %d/%i → signed decimal integer
**   %u  → unsigned decimal integer
**   %x/%X → hex lowercase/uppercase
**   %p  → pointer address (format: 0x...)
**   %%  → literal '%'
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_check(va_list *args, char c);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base_len(long long nbr, char *base);
int	ft_putptr_base_len(unsigned long long nbr, char *base);
int	ft_putpointer(unsigned long long p);

#endif
