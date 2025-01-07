/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:31:00 by hdelacou          #+#    #+#             */
/*   Updated: 2024/12/19 15:19:11 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Free the memory allocated for a stack.
 *
 * @param[in,out] stack The stack to free.
 */
void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

/**
 * Calculate the size of a linked list.
 *
 * @param stack The head of the linked list.
 * @return The number of elements in the list.
 */

int	ft_lstsize(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/**
 * Check if a stack has no duplicate values.
 *
 * @param stack The stack to check.
 * @return 1 if the stack has no duplicate values, 0 otherwise.
 */
int	no_duplicates(t_list *stack)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = stack;
	while (ptr)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (ptr->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return (1);
}

/**
 * Check if a string represents a valid number.
 *
 * This function takes a string pointer as an argument and returns 1 if the
 * string represents a valid number, 0 otherwise.
 *
 * @param str The string to check.
 * @return 1 if the string is a valid number, 0 otherwise.
 */
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * Check if a stack is already sorted in ascending order.
 *
 * @param stack The stack to check.
 * @return 1 if the stack is sorted, 0 otherwise.
 */
int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
