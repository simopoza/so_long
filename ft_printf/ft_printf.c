/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 03:49:27 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/15 01:01:36 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_comp(char c, va_list ali)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ali, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ali, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(ali, int)));
	else if (c == 'u')
		return (ft_putunsignednbr(va_arg(ali, unsigned int)));
	else if (c == 'x')
		return (ft_printfhexlow(va_arg(ali, unsigned int)));
	else if (c == 'X')
		return (ft_printf_hex(va_arg(ali, unsigned int)));
	else if (c == 'p')
		return (ft_address(va_arg(ali, unsigned long)));
	else if (c == '%')
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ali;
	int		i;
	int		l;

	va_start(ali, str);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (i);
			i++;
			l += ft_comp(str[i], ali);
		}
		else
			l += ft_putchar(str[i]);
		i++;
	}
	return (l);
}

/*int main()
{
	printf(" %p %p ", 0, 0);
	ft_printf(" %p %p ", 0, 0);
}*/