/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:50:52 by mannahri          #+#    #+#             */
/*   Updated: 2022/03/18 21:16:21 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_win;
	char	**mape;
	void	*meat;
	void	*lu_up;
	void	*lu_left;
	void	*lu_right;
	void	*lu_down;
	void	*wall;
	void	*lawr;
	void	*bab;
	void	*bab2;
	int		p1;
	int		p2;
	int		k;
	int		l;
	int		c;
	int		b;
	int		h;
	int		i;
	int		j;
	int		count;
}		t_data;

int		main(int ac, char *av[]);
char	**read_map(char *map);
int		ft_strlen(char	*s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);
int		ft_strchr(char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
void	check_rectangul(char **splt);
void	check_l7ayt(char **mape);
int		check_ber(char *str);
int		check_char(char **mape, char c);
void	ft_rasma_dyali(t_data t);
t_data	rsame_wall(t_data t);
t_data	help_rasma(int y, int x, t_data t);
int		handl_key(int key, t_data *t);
void	move_up(t_data *t);
void	move_down(t_data *t);
void	move_left(t_data *t);
void	move_right(t_data *t);
void	coin_decr(t_data *t);
t_data	enemy(int x, int y, t_data t);
int		khroj(int key);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_address(unsigned long long int nb);
int		ft_printfhexlow(unsigned long long int nb);
int		ft_putunsignednbr(unsigned int nb);
int		ft_printf_hex(unsigned long long int nb);

#endif