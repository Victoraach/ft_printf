/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:13:55 by osredond          #+#    #+#             */
/*   Updated: 2024/05/02 20:14:20 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_print_char(int c);
int		ft_printn_base(int n, char *base);
int		ft_printnu_base(unsigned int n, char *base);
int		ft_print_hex(unsigned long n, char *base);
int		ft_print_str(char *s);
size_t	ft_strlenv2(const char *s);

#endif
