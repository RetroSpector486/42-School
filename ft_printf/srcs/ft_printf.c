/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:23:44 by kbolzon           #+#    #+#             */
/*   Updated: 2022/03/23 11:31:35 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*start(void)
{
	t_print	*arg_count;

		arg_count = (t_print *)malloc(sizeof(t_print));
	if (arg_count == NULL)
		return (NULL);
		arg_count->counter = 0;
	return (arg_count);
}

void	printcheck(const char character, t_print *arg_count)
{
	if (character == 'c')
		ifcharacter(arg_count);
	else if (character == 's')
		ifstring(arg_count);
	else if (character == 'p')
		ifpointer(arg_count);
	else if (character == 'i' || character == 'd')
		ifint(arg_count);
	else if (character == 'u')
		ifunsignedint(arg_count);
	else if (character == 'x' || character == 'X')
		ifhex(arg_count, character);
	else if (character == '%')
	{
		ft_putchar_fd('%', 1);
				arg_count->counter++;
	}
	else if (character != '\0')
	{
		write(1, &character, 1);
				arg_count->counter++;
	}
}

int	ft_printf(const char *string, ...)
{
	t_print	*arg_count;
	int		printcomplete;
	int		i;

		i = 0;
		arg_count = start();
		printcomplete = 0;
	va_start(arg_count->args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			printcheck(string[++i], arg_count);
		else
		{
			ft_putchar_fd(string[i], 1);
						arg_count->counter++;
		}
		if (string[i] != '\0')
						i++;
	}
		printcomplete = arg_count->counter;
	va_end(arg_count->args);
	free(arg_count);
	return (printcomplete);
}
