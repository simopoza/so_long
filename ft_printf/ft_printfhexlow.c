/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexlow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:34:40 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/15 01:01:45 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_count(unsigned long long int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static int	ft_zero(unsigned long long int nb)
{
	char	*str;
	int		j;

	j = 0;
	nb = 0;
	str = malloc(sizeof(char) * 2);
	str[j] = '0';
	str[j + 1] = '\0';
	ft_putstr(str);
	free(str);
	return (1);
}

int	ft_printfhexlow(unsigned long long int nb)
{
	char	*l;
	char	*str;
	int		j;
	int		i;

	j = 0;
	if (nb == 0)
		return (ft_zero(nb));
	l = "0123456789abcdef";
	j = ft_count(nb);
	i = j;
	str = malloc(sizeof(char) * (j + 1));
	str[j] = '\0';
	j--;
	while (nb > 0)
	{
		str[j] = l[nb % 16];
		nb /= 16;
		j--;
	}
	ft_putstr(str);
	free(str);
	return (i);
}
