/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:36:28 by kbolzon           #+#    #+#             */
/*   Updated: 2022/12/01 08:57:19 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minitalk.h"

void	handles(int sig)
{
	int	i;

	i = 0;
	g_msg.c += ((sig & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to my Server!!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, handles);
		signal(SIGUSR1, handles);
		pause();
	}
	return (0);
}
