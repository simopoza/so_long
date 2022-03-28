/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 03:49:20 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/15 01:02:03 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_calcul_diviseur(int nbr)
{
	int	i;

	i = 1;
	while (nbr > 9)
	{
		i = i * 10;
		nbr = nbr / 10;
	}
	return (i);
}

static	int	ft_min_putnbr(int nb)
{
	int	j;
	int	d;

	j = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		j++;
	}
	d = ft_calcul_diviseur(nb);
	while (d > 9)
	{
		ft_putchar(nb / d + '0');
		nb = nb - ((nb / d) * d);
		d = d / 10;
		j++;
	}
	ft_putchar(nb + '0');
	j++;
	return (j);
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
		return (ft_min_putnbr(nb));
}
