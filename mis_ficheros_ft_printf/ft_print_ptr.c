/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:42:55 by valvarez          #+#    #+#             */
/*   Updated: 2024/07/03 18:42:59 by valvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(void *ptr)
{
	int			print_length;
	uintptr_t	n;

	n = (uintptr_t) ptr;
	print_length = 0;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		print_length += 5;
	}
	else if (n == 0)
	{
		print_length += write(1, "0x", 2);
		print_length += write(1, "0", 1);
	}
	else
	{
		print_length += write(1, "0x", 2);
		ft_put_ptr(n);
		print_length += ft_ptr_len(n);
	}
	return (print_length);
}
