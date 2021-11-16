/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:03:28 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 23:04:45 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <termios.h>

static void	receiver(int sig_id, siginfo_t *sig, void *context)
{
	struct termios	term;

	(void)context;
	(void)sig;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tcgetattr(0, &term);
	term.c_lflag = 0x2020010d;
	tcsetattr(0, TCSANOW, &term);
	if (sig_id == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig_id == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_signals_main(pid_t pid)
{
	struct sigaction	box;

	box.sa_flags = SA_SIGINFO;
	(void)pid;
	box.__sigaction_u.__sa_sigaction = receiver;
	sigaction(SIGINT, &box, NULL);
	sigaction(SIGQUIT, &box, NULL);
}
