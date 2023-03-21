/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:18:04 by kbolzon           #+#    #+#             */
/*   Updated: 2023/03/20 12:52:54 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include "libft.h"
# include "keys.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITS 60

# define MANDELBROT 1
# define JULIA 2
# define MANDELBOX 3
# define BURNING_SHIP 4

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	int		*palette;
	int		color;
	int		color_pat;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
}	t_fract;

void	render(t_fract *f);
void	color_shift(t_fract *f);
void	set_color_mc(t_fract *f, int color);
void	set_color_multi(t_fract *f, int colors[4], int n);
void	set_color_tetra(t_fract *f, int color);
void	set_color_triad(t_fract *f, int color);
void	set_color_contrast(t_fract *f, int color);
void	set_color_opposite(t_fract *f, int color);
void	set_color_graphic(t_fract *f, int color);
void	set_color_zebra(t_fract *f, int color);

void	init(t_fract *f);
void	clean_init(t_fract *f);
void	reinit_img(t_fract *f);
void	get_complex_layout(t_fract *f);
void	get_colors(t_fract *f, int argc, char **argv);
void	clean_exit(int error_code, t_fract *f);
void	help_msg(t_fract *f);
void	print_controls(void);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

int		julia(t_fract *f, double zr, double zi);
int		julia_shift(int x, int y, t_fract *f);
int		mandelbrot(double cr, double ci);
int		mandelbox(t_fract *f, double cr, double ci);
int		get_color_percent(int color, double percent);
int		ft_ishexdigit(int c);
int		burning_ship(double cr, double ci);
int		ft_isdigit(int i);

int		ft_isspace(int c);
int		main(int argc, char **argv);
int		key_event(int keycode, t_fract *mlx);
int		mouse_event(int keycode, int x, int y, t_fract *mlx);
int		end_fract(t_fract *mlx);
int		msgs(char *s1, char *s2, int errno);
double	ft_atof(char *str);

#endif
