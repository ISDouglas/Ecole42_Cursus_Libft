/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:50:54 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/27 03:15:58 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** - server.h: display_pid()
** - libft.h: ft_putchar_fd()
** - unistd.h: pause()
** - signal.h: signal()
** - stdlib.h: exit()
*/

#include <server.h>
#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*
** This function is the handler for messaging signals (SIGUSR1 = 0,
** SIGUSR2 = 1). It will keep tracking of the received bits until it has
** a full character, printing it and resetting.
*/
static void	handler_msg(int sig)
{
	static struct s_character	chr = {0, 0};

	if (sig == SIGUSR2)
		chr.character |= 1 << chr.current_bit;
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		ft_putchar_fd(chr.character, 1);
		chr.character = 0;
		chr.current_bit = 0;
	}
}

/*
** This function is the handler for terminating signals. It just calls to
** exit(0).
*/
static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(void)
{
	display_pid();
	signal(SIGUSR1, handler_msg);
	signal(SIGUSR2, handler_msg);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
