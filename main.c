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
static void check_buildin(t_ptr *t_ptr)
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
	// if(ft_strncmp(tmp->container, "export", 6) == 0)
	// 	ft_export();
	// if(ft_strncmp(tmp->container, "exeve", 5) == 0)
	// 	ft_execve(mass, tmp);

}


static void ft_check_comm(t_all *mass)
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
	// tmp->count = tmp->container[0];
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
	// while(t_ptr->head)
	// {
		if(t_ptr->head->type == 'c')
			check_buildin(t_ptr);
	// 	t_ptr->head = t_ptr->head->next;
	// }
}

int main (void)
{
	t_all	*mass;

	mass = (t_all*)malloc(sizeof(t_all));


	while (1)
	{
		ft_bzero(mass, sizeof(t_all));
		//mass->buf = ft_strdup("ec'ho' |cho cho");
		mass->buf = readline("Minishell: ");
		if (ft_strlen(mass->buf) > 0)
		{
			add_history(mass->buf);
			ft_parser(mass);
			ft_check_comm(mass);
			ft_token_clean(&(mass->tokens));
		}
		if (mass->buf != NULL)
		{
			free(mass->buf);
			mass->buf = NULL;
		}
		free(mass->buf);
		// if (mass->buf != NULL)
		// {
		// 	free(mass->buf);
		// 	mass->buf = NULL;
		// }
		// if (mass->tmp != NULL)
		// {
		// 	free(mass->tmp);
		// 	mass->tmp = NULL;
		// }
	}
}
