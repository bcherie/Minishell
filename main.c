#include "minishell.h"

static void ft_check_args(t_ptr *t_ptr)
{
	t_ptr->command = NULL;
	t_ptr->tmp1 = t_ptr->start;
	t_ptr->count = 0;
	int i;

	i = 0;
	i = t_ptr->start->index;
	while (i <= t_ptr->end->index)
	{
		if (t_ptr->tmp1->type == 'c')
			t_ptr->command = t_ptr->tmp1;
		else if (t_ptr->tmp1->type == 'a')
			(t_ptr->count)++;
		t_ptr->tmp1 = t_ptr->tmp1->next;
		i++;
	}
	if (t_ptr->command != NULL)
	{
		t_ptr->command->count = t_ptr->count;
		if (t_ptr->count != 0)
		{
			t_ptr->command->args = (char **)malloc(sizeof(char *) * t_ptr->count);
			if (!(t_ptr->command->args))
			{
				exit(-1);
				printf("Error, malloc\n");
			}
			t_ptr->tmp1 = t_ptr->start;
			i = t_ptr->start->index;
			t_ptr->count = 0;
			while (i <= t_ptr->end->index)
			{
				if (t_ptr->tmp1->type == 'a')
				{
					t_ptr->command->args[t_ptr->count] = t_ptr->tmp1->container;
					(t_ptr->count)++;
				}
				t_ptr->tmp1 = t_ptr->tmp1->next;
				i++;
			}
		}
	}
}

static void check_buildin(t_ptr *t_ptr, char **env)
{
	if (ft_strncmp(t_ptr->command->container, "pwd", 3) == 0)
	{
		if(ft_strlen(t_ptr->command->container) == 3)
			ft_pwd();
		else
			printf("command not found\n");
	}
	if (ft_strncmp(t_ptr->command->container, "cd", 2) == 0)
		ft_cd(t_ptr);
	if(ft_strncmp(t_ptr->command->container, "echo", 4) == 0)
		ft_echo(t_ptr);
	// if(ft_strncmp(t_ptr->command->container, "export", 6) == 0)
	// 	ft_export(t_ptr);
	// if(ft_strncmp(tmp->container, "exeve", 5) == 0)
	// 	ft_execve(mass, tmp);
	if(ft_strncmp(t_ptr->command->container, "env", 3) == 0)
		ft_env(t_ptr, env);

}

static	void add_env(char **env)
{
	int	l;
	int	i;
	int j;
	t_tokens	*eniroment = NULL;
	// t_tokens	*head;

	// t_tokens	*new;
	char **tmp = NULL;

	l =	0;
	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char));
	// eniroment = malloc(sizeof(t_tokens));
	// while (env[l] != NULL)
	// 	l++;
	// new = ft_env_create();
	// eniroment = env[i];
	while (env[i] != NULL)
	{
		tmp = ft_split(env[i], '=');
		if (tmp)
			ft_lstadd_back(&eniroment, ft_lstnew(tmp[0], tmp[1]));
		i++;
	}
	tmp = ft_split(env[i], '=');
	if (tmp)
		ft_lstadd_back(&eniroment, ft_lstnew(tmp[0], tmp[1]));
	// while (eniroment->container)
	// {
	// 	// if (eniroment->container[j] == '=')
	// 	// {
	// 		tmp = ft_split(eniroment->container, '=');
	// 		eniroment->key = tmp[0];
	// 		eniroment->value = tmp[1];
	// 	// }
	// 	eniroment = eniroment->next;
	// }
	// 	eniroment = eniroment->next;
	// eniroment->next = new;
	// new->prev = eniroment;
	// new->index = eniroment->index + 1;

	printf("key: %s\n", eniroment->key);
	printf("value: %s\n", eniroment->value);

	// while (eniroment->key[eniroment->count])
	// {
	// 	printf("%s\n", eniroment->key);
	// 	eniroment->count++;
	// }

	//printf("\n%d\n", l);
	// t_ptr->env_args = (char **)malloc(sizeof(char *) * l);
	//printf("\n%s\n", env[5]);
	// while (env[i] != NULL)
	// {
	// 	t_ptr->env_args[i] = env[i];
	// 	i++;
	// }
	// printf("\n%s\n", t_ptr->env_args[5]);

}

static void ft_check_comm(t_all *mass, char **env)
{
	t_tokens	*tmp;
	t_tokens	*command;
	t_ptr		*t_ptr;
	// int start = 0;
	t_ptr = &mass->t_ptrs;
	t_ptr->head = mass->tokens;
	t_ptr->start = t_ptr->head;
	t_ptr->tmp0 = t_ptr->head;
	command = mass->tokens;
	command->st = 0;
	tmp = mass->tokens;
	command->end = 0;
	add_env(env);

	if (t_ptr->start->type == 'p')
	{
		printf("Error!");
		exit(-1);
	}
	while (t_ptr->start)
	{
		if (t_ptr->tmp0->type == 'p' || t_ptr->tmp0->next == NULL)
		{
			if (t_ptr->tmp0->next == NULL)
				t_ptr->end = t_ptr->tmp0;
			else
				t_ptr->end = t_ptr->tmp0->prev;
			ft_check_args(t_ptr);
			t_ptr->start = t_ptr->tmp0->next;
		}
		t_ptr->tmp0 = t_ptr->tmp0->next;
	}
	while (t_ptr->head)
	{
		if (t_ptr->head->type == 'c')
		{
			check_buildin(t_ptr, env);
			break ;
		}
		t_ptr->head = t_ptr->head->next;
	}
}

int main (int argc, char **argv, char **env)
{
	t_all	*mass;
	// int	i;
	// int l;

	(void)argv;
	(void)argc;
	// i =	0;
	// l =	0;
	// env_st = NULL;
	// while (env[l] != NULL)
	// 	l++;
	// //printf("\n%d\n", l);
	// env_st = (t_env *)malloc(sizeof(t_env));
	// env_st->env_args = (char **)malloc(sizeof(char *) * l);
	mass = (t_all*)malloc(sizeof(t_all));

	//printf("\n%s\n", env[5]);
	// while (env[i] != NULL)
	// {
	// 	env_st->env_args[i] = env[i];
	// 	i++;
	// }
	//printf("\n%s\n", env_st->env_args[5]);
	while (1)
	{
		ft_bzero(mass, sizeof(t_all));
		//mass->buf = ft_strdup("echo $? text");
		mass->buf = readline("Minishell: ");
		if (ft_strlen(mass->buf) > 0)
		{
			add_history(mass->buf);
			ft_parser(mass);
			ft_check_comm(mass, env);
			ft_token_clean(&(mass->tokens));
		}
		if (mass->buf != NULL)
		{
			free(mass->buf);
			mass->buf = NULL;
		}
		free(mass->buf);
	}
	return (0);
}
