/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarez <valvarez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:16:30 by valvarez          #+#    #+#             */
/*   Updated: 2024/07/11 15:45:20 by valvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
/*
int main(void)
{
    char *str = "Nathan";
    int num = 42;
    unsigned int unum = 42;
    void *ptr = &num;
    int len;

    ft_printf("Carácter: %c\n", 'N');
    ft_printf("Cadena: %s\n", str);
    ft_printf("El puntero void * se imprime en hexadecimal: %p\n", ptr);
    ft_printf("Imprimiendo n decimal (base 10): %d\n", num);
    ft_printf("Imprimiendo n en base 10: %i\n", num);
    ft_printf("Imprimiendo n decimal (base 10) sin signo: %u\n", unum);
    ft_printf("Imprimiendo n hexadecimal (base 16) en minúsc: %x\n", num);
    ft_printf("Imprimiendo n hexadecimal (base 16) en mayúsc: %X\n", num);
    ft_printf("Imprimiendo símbolo del porcentaje: %%\n");

    ft_printf("hola soy %s, y tengo %d años.\n", "Marvin", 42) ;
    
    return 0;
}*/
