/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarez <valvarez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:16:30 by valvarez          #+#    #+#             */
/*   Updated: 2024/07/15 12:01:57 by valvarez         ###   ########.fr       */
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
		print_length += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	else
		print_length += ft_printnoexistentconversion(format);
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
    int num_hex = 2707;
    unsigned int unum = 42;
	int num = 42;
	void * ptr = &num;
    void *ptrnull = NULL;

    ft_printf("Carácter: %c\n", 'N');
    ft_printf("Cadena: %s\n", str);
    ft_printf("Ptr void * se imprime en hexadecimal: %p\n", ptr);
	ft_printf("Ptr de NULL void * se imprime en hexa ft_printf: %p\n", ptrnull);
    printf("Puntero de NULL void * se imprime en hexa printf: %p\n", ptrnull);
	ft_printf("Imprimiendo n decimal (base 10): %d\n", num);
    ft_printf("Imprimiendo n en base 10: %i\n", num);
    ft_printf("Imprimiendo n decimal (base 10) sin signo: %u\n", unum);
    ft_printf("Imprimiendo n hexadecimal (base 16) en minúsc: %x\n", num_hex);
    ft_printf("Imprimiendo n hexadecimal (base 16) en mayúsc: %X\n", num_hex);
    ft_printf("Imprimiendo símbolo del porcentaje: %%\n");
	ft_printf("Imprimiendo símbolo distinto a los pedidos: %k\n");
    ft_printf("Soy %s, y tengo %d juguetes en mi casa.\n", str, num_hex) ;
    return 0;
}*/