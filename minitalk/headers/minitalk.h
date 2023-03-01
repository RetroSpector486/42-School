/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:58:35 by kbolzon           #+#    #+#             */
/*   Updated: 2022/12/01 08:26:34 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/signal.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		counter;
}		t_print;

typedef struct s_message
{
	char	c;
	size_t	i;
}	t_message;

t_message	g_msg;

void	ifcharacter(t_print *arg_count);
void	ifstring(t_print *arg_count);
void	ifpointer(t_print *arg_count);
void	ifhex(t_print *arg_count, char character);
void	ifint(t_print *arg_count);
void	ifunsignedint(t_print *arg_count);
int		ft_printf(const char *string, ...);

#endif