/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:53:05 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/15 01:16:14 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *t)
{
	if (t->mape[t->p1 - 1][t->p2] == 'E' && t->c == 0)
		exit(0);
	if (t->mape[t->p1][t->p2] == 'P' && t->mape[t->p1 - 1][t->p2] != '1'\
	&& t->mape[t->p1 - 1][t->p2] != 'E')
	{
		ft_printf("move number : %d\n", ++t->count);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lawr, \
		t->p2 * 50, t->p1 * 50);
		t->mape[t->p1][t->p2] = '0';
		if (t->mape[t->p1 - 1][t->p2] == 'C')
			coin_decr(t);
		t->p1--;
		t->mape[t->p1][t->p2] = 'P';
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lu_up, \
		t->p2 * 50, t->p1 * 50);
	}
}

void	move_down(t_data *t)
{
	if (t->mape[t->p1 + 1][t->p2] == 'E' && t->c == 0)
		exit(0);
	if (t->mape[t->p1][t->p2] == 'P' && t->mape[t->p1 + 1][t->p2] != '1'\
	&& t->mape[t->p1 + 1][t->p2] != 'E')
	{
		if (t->mape[t->p1 + 1][t->p2] == 'C')
			coin_decr(t);
		ft_printf("move number : %d\n", ++t->count);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lawr, \
		t->p2 * 50, t->p1 * 50);
		t->mape[t->p1][t->p2] = '0';
		t->p1++;
		t->mape[t->p1][t->p2] = 'P';
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lu_up, \
		t->p2 * 50, t->p1 * 50);
	}
}

void	move_left(t_data *t)
{
	if (t->mape[t->p1][t->p2 - 1] == 'E' && t->c == 0)
		exit(0);
	if (t->mape[t->p1][t->p2] == 'P' && t->mape[t->p1][t->p2 - 1] != '1'\
	&& t->mape[t->p1][t->p2 - 1] != 'E')
	{
		if (t->mape[t->p1][t->p2 - 1] == 'C')
			coin_decr(t);
		ft_printf("move number : %d\n", ++t->count);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lawr, \
		t->p2 * 50, t->p1 * 50);
		t->mape[t->p1][t->p2] = '0';
		t->p2--;
		t->mape[t->p1][t->p2] = 'P';
		t->lu_left = mlx_xpm_file_to_image(t->mlx_ptr, \
		"luffy_left.xpm", &t->k, &t->l);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lu_left, \
		t->p2 * 50, t->p1 * 50);
	}
}

void	move_right(t_data *t)
{
	if (t->mape[t->p1][t->p2 + 1] == 'E' && t->c == 0)
		exit(0);
	if (t->mape[t->p1][t->p2] == 'P' && t->mape[t->p1][t->p2 + 1] != '1'\
	&& t->mape[t->p1][t->p2 + 1] != 'E')
	{
		if (t->mape[t->p1][t->p2 + 1] == 'C')
			coin_decr(t);
		ft_printf("move number : %d\n", ++t->count);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lawr, \
		t->p2 * 50, t->p1 * 50);
		t->mape[t->p1][t->p2] = '0';
		t->p2++;
		t->mape[t->p1][t->p2] = 'P';
		t->lu_right = mlx_xpm_file_to_image(t->mlx_ptr, \
		"luffy_right.xpm", &t->k, &t->l);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->lu_right, \
		t->p2 * 50, t->p1 * 50);
	}
}
