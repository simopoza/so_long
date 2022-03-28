/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:12:16 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/16 15:07:35 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char **mape, char c)
{
	int	i;
	int	j;
	int	l;

	l = 0;
	i = 0;
	while (mape[i])
	{
		j = 0;
		while (mape[i][j])
		{
			if (mape[i][j] == c)
				l++;
			if (mape[i][j] == '1' || mape[i][j] == '0' || mape[i][j] == 'C' \
			|| mape[i][j] == 'E' || mape[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (l);
}

void	check_rectangul(char **splt)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (splt[0][x])
	{
		if (splt[0][x] != '1')
		{
			write(2, "Error.", 7);
			exit (0);
		}
		x++;
	}
	while (splt[y])
	{
		if ((ft_strlen(splt[y]) != x))
		{
			write (2, "This is not a ectangul.", 24);
			exit(0);
		}
		y++;
	}
}

void	check_l7ayt(char **mape)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mape[j])
	{
		if (mape[j][0] != '1' || mape[j][ft_strlen(mape[j]) - 1] != '1')
		{
			write (1, "hara lwahd", 11);
			exit (1);
		}
		j++;
	}
	while (mape[j - 1][i])
	{
		if (mape[j - 1][i] != '1')
		{
			write (1, "lhayt nabk", 11);
			exit (0);
		}
		i++;
	}
}

int	file(char	*map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error this map does not exist.", 31);
		exit(0);
	}
	return (fd);
}

char	**read_map(char *map)
{
	char	**mape;
	char	*new;
	char	*str;
	int		fd;

	str = malloc(1);
	if (!str)
		free (str);
	free (str);
	fd = file(map);
	new = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		new = ft_strjoin(new, str);
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	mape = ft_split(new, '\n');
	free (new);
	return (mape);
}
