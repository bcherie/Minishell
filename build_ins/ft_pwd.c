#include "../minishell.h"

char	*ft_pwd(int type)
{
	char	*path;
	char	*buffer;

	buffer = NULL;
	path = getcwd(buffer, sizeof(buffer));
	if (type == 1)
		printf("%s\n", path);
	return (path);
}
