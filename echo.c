#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

int     ft_strcmp(char *s1, char *s2)
{
    int     i;
    
	i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int	ft_echo(t_list *args)
{
	t_list	*curr;
	int		flag;

	flag = 0;
	if (!curr)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	curr = args;
	curr = curr->next;
	if (ft_strcmp(curr->content, "-n") == 0)
	{
		flag = 1;
		curr = curr->next;
	}
	while (curr)
	{
		//printf("%s\n", (char *)args->content);
		ft_putstr_fd(curr->content, 1);
		curr = curr->next;
		if (curr)
			ft_putstr_fd(" ", 1);
	}
	if (flag != 1)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**str;
	int		i;
	t_list	*args;

	str = ft_split("echo hello to yo", ' ');
	i = 0;
	args = NULL;
	while (str[i])
	{
		//printf("%s\n", str[i]);
		ft_lstadd_back(&args, ft_lstnew((char *)str[i]));
		i++;
	}
	ft_echo(args);

	return (0);
}
