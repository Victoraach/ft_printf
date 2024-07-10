/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnu_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:17:08 by osredond          #+#    #+#             */
/*   Updated: 2024/05/02 20:17:26 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_num_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		(n /= 10);
		len++;
	}
	return (len);
}

int	ft_printnu_base(unsigned int n, char *base)
{
	unsigned int	bhex;

	bhex = ft_strlenv2(base);
	if (n == 2147483648)
	{
		ft_print_char('2');
		ft_printn_base(147483648, base);
	}
	else if (n < bhex)
		ft_print_char(base[n]);
	else
	{
		ft_printnu_base(n / bhex, base);
		ft_print_char(base[n % bhex]);
	}
	return (ft_num_len(n));
}
/*
int	main(void)
{
	const char	typhex[] = "0123456789";

	printf("%u\n", printn_base(2147483647, &typex));
	return (0)
}*/
