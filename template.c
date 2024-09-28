#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int		nb;
	struct s_list	*next;
}	t_list;

t_list	*init_list(int argc, char **argv)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = NULL;
	i = 0;
	while (i < argc - 1)
	{
		tmp = (t_list*)malloc(sizeof(t_list));
		if (!tmp)
			return (NULL);
		tmp->nb = atoi(argv[i + 1]);
		tmp->next = list;
		list = tmp;
		i++;
	}
	return (list);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d ", list->nb);
		list = list->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = init_list(argc, argv);
	b = NULL;
	print_list(a);
	return (0);
}

