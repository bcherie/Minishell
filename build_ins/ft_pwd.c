#include "../minishell.h"

void ft_pwd(void)
{
	char *path;
	char *buffer = NULL;

	path = getcwd(buffer, sizeof(buffer));
	printf("%s\n", path);
}
