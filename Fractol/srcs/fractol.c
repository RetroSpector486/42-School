/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:13:57 by kbolzon           #+#    #+#             */
/*   Updated: 2023/03/20 10:36:37 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static int	type_cmp(char *argv, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = ft_tolower(argv[i]);
		i++;
	}
	if (!ft_strncmp(argv, str, ft_strlen(str) + 1))
		return (1);
	else if (argv[1] == '\0' && (argv[0] == c || argv[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_fract *f, char **argv)
{
	if (type_cmp(argv[1], "mandelbrot", 'm', '1'))
		f->set = MANDELBROT;
	else if (type_cmp(argv[1], "julia", 'j', '2'))
		f->set = JULIA;
	else if (type_cmp(argv[1], "mandelbox", 'x', '3'))
		f->set = MANDELBOX;
	else if (type_cmp(argv[1], "burning ship", 'b', '3'))
		f->set = BURNING_SHIP;
	else
		help_msg(f);
}

static void	get_julia_start_values(t_fract *f, int argc, char **argv)
{
	if (f->set != JULIA || argc == 2)
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
		return ;
	}
	if (argc == 3)
		help_msg(f);
	if (!ft_strchr(argv[2], '.'))
		help_msg(f);
	if (!ft_strchr(argv[3], '.'))
		help_msg(f);
	f->kr = ft_atof(argv[2]);
	f->ki = ft_atof(argv[3]);
	if (f->kr > 2.0 || f->kr <= -2.0)
		help_msg(f);
	if (f->ki >= 2.0 || f->ki <= -2.0)
		help_msg(f);
}

static void	handle_args(t_fract *f, int argc, char **argv)
{
	get_set(f, argv);
	if (f->set != JULIA && argc > 3)
		help_msg(f);
	else if (f->set == JULIA && argc > 5)
		help_msg(f);
	get_julia_start_values(f, argc, argv);
	get_colors(f, argc, argv);
}

int	main(int argc, char **argv)
{
	t_fract	f;

	if (argc < 2)
		help_msg(&f);
	clean_init(&f);
	handle_args(&f, argc, argv);
	init(&f);
	render(&f);
	print_controls();
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fract, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
