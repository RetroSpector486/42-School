/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:11:42 by kbolzon           #+#    #+#             */
/*   Updated: 2023/03/18 15:53:17 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static void	color_shift_special(t_fract *f)
{
	int	alt_color;

	if (f->color == 0xFFFFFF)
			alt_color = 0xCCCCCC;
	else
		alt_color = f->color;
	if (f->color_pat == 5)
		set_color_contrast(f, alt_color);
	else if (f->color_pat == 6)
		set_color_opposite(f, f->color);
	else if (f->color_pat == 7)
		set_color_graphic(f, f->color);
	else if (f->color_pat == 8)
		set_color_multi(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

static void	color_shift_striped(t_fract *f)
{
	if (f->color_pat == 2)
		set_color_zebra(f, f->color);
	else if (f->color_pat == 3)
		set_color_triad(f, f->color);
	else if (f->color_pat == 4)
		set_color_tetra(f, f->color);
	else
		color_shift_special(f);
}

void	color_shift(t_fract *f)
{
	int	alt_color;

	f->color_pat = (f->color_pat + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pat == 0)
		set_color_mc(f, alt_color);
	else if (f->color_pat == 1)
		set_color_multi(f, (int [4]){0x000000, alt_color,
			get_color_percent(f->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(f);
}
