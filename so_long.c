/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:15:04 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/18 21:13:35 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_data	t;

	if (ac != 2)
	{
		write (2, "Error arguments.", 17);
		exit(0);
	}
	if (!check_ber(av[1]))
	{
		write (1, "ber nabk", 9);
		exit (1);
	}
	t.mape = read_map(av[1]);
	check_rectangul(t.mape);
	check_l7ayt(t.mape);
	if (!check_char(t.mape, '1') || !check_char(t.mape, '0') || \
	!check_char(t.mape, 'E') || check_char(t.mape, 'P') != 1 || \
	!check_char(t.mape, 'C'))
	{
		write (1, "Error in map\n", 14);
		exit (0);
	}
	ft_rasma_dyali(t);
	return (0);
}
