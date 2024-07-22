/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:14:41 by valvarez          #+#    #+#             */
/*   Updated: 2024/07/09 19:00:57 by valvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnoexistentconversion(char c);
int		ft_print_ptr(void *ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);
int		ft_ptr_len(uintptr_t num);
int		ft_num_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
void	ft_putstr(char *str);
void	ft_put_ptr(uintptr_t num);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);

#endif
