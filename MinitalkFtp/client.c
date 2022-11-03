/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:54:54 by thfirmin          #+#    #+#             */
/*   Updated: 2022/11/02 16:10:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_message;

void	ft_return(int signum);

int		ft_isalldigit(char	*str);

void	ft_atobin(char c, int bit, pid_t pid_n, int mod);

int	main(int argc, char *argv[])
{
	pid_t	n_pid;

	if ((argc != 3) || (!ft_isalldigit(argv[1])))
	{
		ft_printf("\e[38;5;196mERROR: \e[mincorrect argument!\e[38;5;87m\n");
		ft_printf("NOTE: \e[mCorrect Argument format [./client <PID> <STR>]\n");
		exit(EXIT_FAILURE);
	}
	n_pid = ft_atoi(argv[1]);
	g_message = argv[2];
	ft_atobin(0, 0, n_pid, 1);
	signal (SIGUSR1, ft_return);
	signal (SIGUSR2, ft_return);
	kill (n_pid, SIGUSR1);
	sleep (1);
	kill (getpid(), SIGUSR2);
}

/*int	main(int argc, char *argv[])
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
	message = argv[2];
	while (*argv[2])
		ft_atobin(*argv[2]++, n_pid);
	ft_atobin(0, n_pid);
	kill(getpid(), SIGUSR2);
}*/

void	ft_atobin(char c, int bit, pid_t pid_n, int mod)
{
	static int	n_pid;

	if (mod)
	{
		n_pid = pid_n;
	}
	else
	{
		if (c & (1 << bit))
			kill (n_pid, SIGUSR1);
		else
			kill (n_pid, SIGUSR2);
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
	static int	connection;
	static int	bit = 8;

	if (signum == SIGUSR1)
	{
		if (!connection)
			connection = 1;
		if (!bit)
		{
			g_message ++;
			bit = 8;
		}
		if (*g_message)
			ft_atobin(*g_message, --bit, 0, 0);
		else
			ft_atobin(0, --bit, 0, 0);
	}
	else
	{
		if (!connection)
		{
			ft_printf ("Failed to connect to Server!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_printf("\e[32mMessage has been delivered\n");
			exit(EXIT_SUCCESS);
		}
	}
}
