#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>

void	run_exec_folders(t_tokens *tok, char **exec_folders)
{
	int     i;
	char    *tmp;
	char    *current_f;
	char    *sym = "/";
	struct stat buf;
	i = 0;
	while (exec_folders[i])
	{
		current_f = ft_strjoin(exec_folders[i], sym);
		tmp = ft_strjoin(current_f, tok->container);
		if (stat(tmp, &buf) == 0)
		{
			execve(tmp, tok->args, NULL);
			tok->container = NULL;
		}
		free(tmp);
		// else
		//     printf("I'm so sorry\n");
		i++;
	}
}

void	run_current_p(t_tokens *tok, char *current_path)
{
    char	*tmp;
    char	*tmp2;
    char	*sym = "/";
    struct	stat buf;

	tmp = ft_strjoin(current_path, sym);
	tmp2 = ft_strjoin(tmp, tok->container);
	if (stat(tmp2, &buf) == 0)
	{
		execve(tmp2, tok->args, NULL);
		tok->container = NULL;
	}
}

void    ft_find_exec(t_all *mass, t_tokens *tok)
{
    // struct stat buf; // структура, где будет храниться инфа о файле

    char    *path;
    char    *current_path;
    char    **exec_folders;
    // char    **mass_env;
    // int     i;


    pid_t pid;

    // t_tokens *env;

    // env = mass->environment;
    // mass_env = (char **) malloc(sizeof(char *));
    // printf ("key %s\n",  env->key);
    // while (env)
    // {


    //     v1 = ft_strjoin(env->key, "=");
    //     // hran = v1;
    //     v2 = ft_strjoin(v1, env->value);
    //     // hran2 = v2;
    //     i = 0;
    //     while (v2[i])
    //     {
    //         mass_env[i] = &v2[i];
    //         i++;
    //     }
    //     // free(v1);
    //     // free(v2);
    //     env = env->next;
    //     (*mass_env)++;

    // }
    // printf ("mass0^ %s\n",  mass_env[0]);
    // printf ("mass1^ %s\n",  mass_env[1]);
    path = ft_envops_getval(mass, "PATH"); // path из env
    exec_folders = ft_split(path, ':');
    current_path = ft_envops_getval(mass, "PWD");
    // else
    //     printf("PWD doesn't exist\n");
    pid = fork();
	if (pid == 0)
	{
		printf("Child process PID[%d] start running, my parent PID is [%d] \n", getpid(), getppid());
		if (path)
		{
			run_exec_folders(tok, exec_folders);
		}
		else if (current_path)
		{
			run_current_p(tok, current_path);
		}
		else
		{
			printf("Command hasn't found\n");
		}
	}
	if (pid != 0)
		wait(NULL);
}
