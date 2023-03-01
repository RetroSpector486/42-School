/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:36:26 by kbolzon           #+#    #+#             */
/*   Updated: 2022/12/01 09:12:38 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minitalk.h"

void	send_signal(int pid, char *str, size_t len)
{
	int		bit;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		bit = 0;
		while (bit < 7)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit++;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_signal(pid, str, ft_strlen(str));
		ft_printf("Signal Recieved!\n");
	}
	else
		ft_printf("Must not left blank and must type at least 1 word!\n");
}
