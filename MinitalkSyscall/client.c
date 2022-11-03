/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                          :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:54:54 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/23 03:47:43 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_return(int signum);

int		ft_isalldigit(char	*str);

void	ft_atobin(char c, pid_t n_pid);

int	main(int argc, char *argv[])
{
	pid_t	n_pid;

	signal(SIGUSR1, ft_return);
	signal(SIGUSR2, ft_return);
	if ((argc != 3) || (!ft_isalldigit(argv[1])))
	{
		ft_printf("\e[38;5;196mERROR: \e[mincorrect argument!\e[38;5;87m\n");
		ft_printf("NOTE: \e[mCorrect Argument format [./client <PID> <STR>]\n");
		exit(EXIT_FAILURE);
	}
	n_pid = ft_atoi(argv[1]);
	while (*argv[2])
		ft_atobin(*argv[2]++, n_pid);
	ft_atobin(0, n_pid);
	kill(getpid(), SIGUSR2);
}

void	ft_atobin(char c, pid_t n_pid)
{
	int	count;

	count = 8;
	while (count--)
	{
		if (c & (1 << count))
			kill (n_pid, SIGUSR2);
		else
			kill (n_pid, SIGUSR1);
		usleep(250);
	}
}

int	ft_isalldigit(char	*str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

void	ft_return(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf ("Success sending message!\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf ("Failed to send message!\n");
		exit(EXIT_FAILURE);
	}
}
