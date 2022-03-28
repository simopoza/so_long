/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:01:00 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/15 01:02:20 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_calcul_diviseur(unsigned int nbr)
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

int	ft_putunsignednbr(unsigned int nb)
{
	int	d;
	int	j;

	j = 0;
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
