/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:52:08 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/05 23:33:08 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Bring a value to the top of the stack using the smallest number
 * of ra or rra operations.
 *
 * @param stack The stack to operate on
 * @param value The value to bring to the top
 * @param stack_name The name of the stack, either 'a' or 'b'
 */
void	bring_to_top(t_list **stack, int value, char stack_name)
{
	int	pos;

	pos = find_position(*stack, value);
	if (pos <= ft_lstsize(*stack) / 2)
	{
		while ((*stack)->value != value)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while ((*stack)->value != value)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

/*
 * Find the position of a given value in a stack
 *
 * @param stack The stack to search
 * @param value The value to find
 * @return The position of the value in the stack, or -1 if not found
 */
int	find_position(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

/*
 * Rotate the stack until the lowest value is at the top.
 *
 * @param stack_a The stack to finalize
 */
void	finalize_sort(t_list **stack_a)
{
	int		min_value;
	t_list	*tmp;

	min_value = (*stack_a)->value;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value < min_value)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	bring_to_top(stack_a, min_value, 'a');
}

/**
 * Sort a stack of 3 elements
 *
 * @param stack_a The stack to sort
 */
void	sort_three(t_list **stack_a)
{
	int	highest_value;

	if (is_sorted(*stack_a))
		return ;
	highest_value = find_max_value(*stack_a);
	if ((*stack_a)->value == highest_value)
		ra(stack_a);
	else if ((*stack_a)->next->value == highest_value)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

/**
 * Sort a stack of 5 elements
 *
 * @param stack_a The primary stack to sort
 * @param stack_b The secondary stack used for sorting
 */
void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min_value;
	t_list	*current;

	if (is_sorted(*stack_a))
		return ;
	while (ft_lstsize(*stack_a) > 3)
	{
		min_value = (*stack_a)->value;
		current = *stack_a;
		while (current)
		{
			if (current->value < min_value)
				min_value = current->value;
			current = current->next;
		}
		bring_to_top(stack_a, min_value, 'a');
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
