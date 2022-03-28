/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:28:09 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/16 15:05:40 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	if (str[i + 1] != 'b')
		return (0);
	if (str[i + 2] != 'e')
		return (0);
	if (str[i + 3] != 'r')
		return (0);
	if (str[i + 4])
		return (0);
	return (1);
}
