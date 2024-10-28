/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:04:03 by lybey             #+#    #+#             */
/*   Updated: 2024/04/17 23:28:29 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_syncflag;

void	feedback(int signum)
{
	if (signum == SIGUSR1)
		g_syncflag = 1;
	else if (signum == SIGUSR2)
		write(1, "Bien recu\n", 10);
}

void	char_to_bin(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_syncflag == 0)
			usleep(200);
		g_syncflag = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &feedback);
	signal(SIGUSR2, &feedback);
	if (pid == 4194305 || pid <= 0 || kill(pid, 0))
	{
		write(2, "Error\n", 7);
		return (1);
	}
	while (argv[2][i])
		char_to_bin(pid, argv[2][i++]);
	if (i > 0 && argv[2][i] == 0)
		char_to_bin(pid, '\0');
}
