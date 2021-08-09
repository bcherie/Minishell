#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "struct.h"

int main (int argc, char **argv, char **env)
{
	t_all mass;
	//init(mass);
	while (1)
	{
		mass.buf = redline("Minishell: ");
	}
	printf("Allright\n");
	return (0);
}
