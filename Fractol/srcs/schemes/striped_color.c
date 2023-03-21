/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striped_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:52:54 by kbolzon           #+#    #+#             */
/*   Updated: 2023/03/15 14:03:10 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static void	fill_stripes_color(t_fract *f, int color, int stripe)
{
	int	i;

	i = 0;
	while (i < MAX_ITS)
	{
		f->palette[i] = color;
		i += stripe;
	}
}

int	get_color_percent(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

void	set_color_zebra(t_fract *f, int color)
{
	int	color2;

	color2 = get_color_percent(color, 50);
	fill_stripes_color(f, color, 1);
	fill_stripes_color(f, color2, 2);
	f->palette[MAX_ITS - 1] = 0;
}

void	set_color_triad(t_fract *f, int color)
{
	int	triad[2];

	triad[0] = get_color_percent(color, 33);
	triad[1] = get_color_percent(color, 66);
	fill_stripes_color(f, color, 1);
	fill_stripes_color(f, triad[0], 2);
	fill_stripes_color(f, triad[1], 3);
	f->palette[MAX_ITS - 1] = 0;
}

void	set_color_tetra(t_fract *f, int color)
{
	int	tetra[3];

	tetra[0] = get_color_percent(color, 25);
	tetra[1] = get_color_percent(color, 50);
	tetra[2] = get_color_percent(color, 75);
	fill_stripes_color(f, color, 1);
	fill_stripes_color(f, tetra[0], 2);
	fill_stripes_color(f, tetra[1], 3);
	fill_stripes_color(f, tetra[2], 4);
	f->palette[MAX_ITS - 1] = 0;
}
