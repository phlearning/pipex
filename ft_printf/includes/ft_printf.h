/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:46:24 by pvong             #+#    #+#             */
/*   Updated: 2023/01/16 15:01:04 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

/* Char & str */
int				ft_printchar(char c);
int				ft_printstr(const char *str);
/* nbr */
int				ft_get_unbr_len(unsigned int n);
char			*ft_uitoa(unsigned int n);
int				ft_printnbr(int n);
unsigned int	ft_printunbr(unsigned int n);
/* HEX */
int				ft_hex_len(unsigned int n);
void			ft_puthex(unsigned int n, char type);
int				ft_printhex(unsigned int n, char type);
/* PTR */
int				ft_ptr_len(uintptr_t n);
void			ft_put_ptr(uintptr_t n);
int				ft_printptr(unsigned long long n);

/* ft_printf */
int				ft_get_format(va_list args, char specifier);
int				ft_printf(const char *str, ...);

#endif