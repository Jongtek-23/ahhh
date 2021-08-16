#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_pwd(void)
{
	int 	res;
	char	str[PATH_MAX];

	res = 0;
	if (getcwd(str, PATH_MAX) == NULL)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		ft_putendl_fd(str, STDOUT_FILENO);
	}
	//res = 1;
	return (res);
}

int	exec_cmd(char *str)
{
	int	res;

	if (ft_strcmp(str, "pwd") == 0)
		res = ft_pwd();
	return (res);
}

int	builtin(char *str)
{
	if (ft_strcmp(str, "pwd") == 0)
		return (1);
	return (0);
}

int	main()
{
	char *str;
	int	res;

	str = "pwd";

	res = builtin(str);
	if (res == 0)
		return (1);

	res = exec_cmd(str);
	if (res == 1)
		return (1);
	return (0);
}
