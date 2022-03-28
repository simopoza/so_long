/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:05:47 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/15 01:47:51 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_decr(t_data *t)
{
	t->mape[t->p1][t->p2] = '0';
	--t->c;
}

int	khroj(int key)
{
	if (key < 0)
		exit (0);
	return (0);
}

int	handl_key(int key, t_data *t)
{
	if (key == 53)
	{
		mlx_destroy_window(t->mlx_ptr, t->mlx_win);
		exit (1);
	}
	if (key == 13 || key == 126)
		move_up(t);
	else if (key == 1 || key == 125)
		move_down(t);
	else if (key == 0 || key == 123)
		move_left(t);
	else if (key == 2 || key == 124)
		move_right(t);
	return (0);
}
