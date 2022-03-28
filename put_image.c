/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:11:52 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/28 13:05:21 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	enemy(int x, int y, t_data t)
{
	t.bab = mlx_xpm_file_to_image(t.mlx_ptr, "sad_bab.xpm", &t.k, &t.l);
	mlx_put_image_to_window(t.mlx_ptr, t.mlx_win, t.bab, x * 50, y * 50);
	t.b = x;
	t.h = y;
	return (t);
}

t_data	help_rasma(int y, int x, t_data t)
{
	t.lawr = mlx_xpm_file_to_image(t.mlx_ptr, "lawr.xpm", &t.k, &t.l);
	mlx_put_image_to_window(t.mlx_ptr, t.mlx_win, t.lawr, x * 50, y * 50);
	if (t.mape[y][x] == '1')
	{
		t.wall = mlx_xpm_file_to_image(t.mlx_ptr, "wall.xpm", &t.k, &t.l);
		mlx_put_image_to_window(t.mlx_ptr, t.mlx_win, t.wall, x * 50, y * 50);
	}
	if (t.mape[y][x] == 'C')
	{
		t.meat = mlx_xpm_file_to_image(t.mlx_ptr, "meat.xpm", &t.k, &t.l);
		mlx_put_image_to_window(t.mlx_ptr, t.mlx_win, t.meat, x * 50, y * 50);
		t.c++;
	}
	if (t.mape[y][x] == 'P')
	{
		t.lu_up = mlx_xpm_file_to_image(t.mlx_ptr, "luffy_up.xpm", &t.k, &t.l);
		mlx_put_image_to_window(t.mlx_ptr, t.mlx_win, t.lu_up, x * 50, y * 50);
		t.p1 = y;
		t.p2 = x;
	}
	if (t.mape[y][x] == 'E')
		t = enemy(x, y, t);
	return (t);
}

t_data	rsame_wall(t_data t)
{
	int		x;
	int		y;

	y = 0;
	while (t.mape[y])
	{
		x = 0;
		while (t.mape[y][x])
		{
			t = help_rasma(y, x, t);
			x++;
		}
		y++;
	}
	return (t);
}

void	ft_rasma_dyali(t_data t)
{
	t.k = 0;
	t.l = 0;
	while (t.mape[t.l][t.k])
		t.k++;
	while (t.mape[t.l])
		t.l++;
	t.mlx_ptr = mlx_init();
	t.mlx_win = mlx_new_window(t.mlx_ptr, t.k * 50, t.l * 50, "so_long");
	t = rsame_wall(t);
	mlx_key_hook(t.mlx_win, handl_key, &t);
	mlx_hook(t.mlx_win, 17, 1L << 2, khroj, &t);
	mlx_loop(t.mlx_ptr);
}
