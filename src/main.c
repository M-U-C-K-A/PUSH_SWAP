/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:16:04 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/05 22:38:49 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Add a new element to the end of the linked list.
 *
 * @param alst The address of the head of the linked list.
 * @param new The new element to add.
 */
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (alst && *alst)
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if (alst)
		*alst = new;
}

/**
 * Creates a new node of type t_list, containing the value provided as content.
 * If content is NULL, the value of the new node is set to 0.
 * @param content the value to be stored in the new node (can be NULL)
 * @return the newly created node
 */
t_list	*ft_lstnew(void const *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content)
		new->value = *(long *)content;
	else
		new->value = 0;
	new->next = NULL;
	return (new);
}

/**
 * @brief Create a linked list from command line arguments
 * @param argc number of command line arguments
 * @param argv command line arguments
 * @return linked list containing the values of the command line arguments
 * @details
 * All values are tested to be in the range of an int and to be
 * only composed of numbers. If any of these tests fails, the linked
 * list is freed and NULL is returned.
 */
t_list	*init_stack(int argc, char **argv)
{
	t_list	*stack;
	t_list	*new_node;
	int		i;
	int		value;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (atol(argv[i]) > INT_MAX || atol(argv[i]) < INT_MIN)
			write(2, "Error: Values out of range\n", 27);
		if (!ft_isnumber(argv[i]))
			write(2, "Error: Values are not numbers\n", 30);
		if ((atol(argv[i]) > INT_MAX || atol(argv[i]) < INT_MIN)
			|| (!ft_isnumber(argv[i])))
		{
			free_stack(&stack);
			return (NULL);
		}
		value = atoi(argv[i]);
		new_node = ft_lstnew(&value);
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}

/**
 * Find the maximum value in the stack.
 *
 * @param stack The stack to search for the maximum value.
 * @return The maximum value found in the stack.
 */
int	find_max_value(t_list *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

/**
 * The main function of the program.
 *
 * This function first initializes a stack from the command line arguments.
 * If the stack is not valid (i.e. the command line arguments are not valid
 * numbers or there are duplicate numbers), it prints an error message and
 * returns 1.
 *
 * If the stack is valid, it sorts it using either the sort_three, sort_five,
 * or turksort functions, depending on the number of elements in the stack.
 *
 * Finally, it frees the memory allocated for the stacks and returns 0.
 */
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (1);
	if (!no_duplicates(stack_a))
		write(2, "Error: Duplicate values found\n", 30);
	else
	{
		if (argc == 4)
			sort_three(&stack_a);
		else if (argc == 6)
			sort_five(&stack_a, &stack_b);
		else
			turksort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
