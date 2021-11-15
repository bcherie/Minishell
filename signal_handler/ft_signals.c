#include <signal.h>
#include "../minishell.h"



static void receiver(int sig_id, siginfo_t *sig, void *context)
{
	(void)context;
	(void)sig;
	(void)sig_id;
	if (sig_id == SIGINT)
	{

	}
	if (sig_id == SIGQUIT)
	{

	}
	if (sig_id == SIGUSR1)
	{

	}
	if (sig_id == SIGUSR2)
	{

	}
}


void	ft_signals_main(pid_t pid)
{
	struct sigaction	box;

	box.sa_flags = SA_SIGINFO;
	box.__sigaction_u.__sa_sigaction = receiver;
	sigaction(SIGINT, &box, NULL);
	sigaction(SIGQUIT, &box, NULL);
	sigaction(SIGUSR1, &box, NULL);
}