/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:30:21 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/07 01:13:31 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Sorts the elements in stack_a using the turksort algorithm.
 *
 * The algorithm divides the elements into chunks and pushes them to stack_b.
 * After all elements are divided and pushed, stack_b is sorted and the elements
 * are moved back to stack_a in sorted order.
 *
 * @param stack_a A double pointer to the head of the first stack to be sorted.
 * @param stack_b A double pointer to the second stack's head.
 */
void	turksort(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;
	int	total_chunks;
	int	i;

	if (is_sorted(*stack_a))
		return ;
	chunk_size = calculate_chunk_size(*stack_a);
	total_chunks = (ft_lstsize(*stack_a) + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < total_chunks)
	{
		push_to_stack_b(stack_a, stack_b, chunk_size, i);
		i++;
	}
	sort_stack_b(stack_a, stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
	finalize_sort(stack_a);
}

/**
 * Calculates the chunk size to be used in the turksort algorithm.
 *
 * This function uses a heuristic to determine the best chunk size based on the
 * size of the stack. For stacks of size 10 or less, the chunk size is 3. For
 * stacks of size 100 or less, the chunk size is size / 5. For larger stacks, the
 * chunk size is size / 10.
 *
 * @param stack A pointer to the head of the stack.
 * @return The calculated chunk size.
 */
int	calculate_chunk_size(t_list *stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (size <= 10)
		return (3);
	else if (size <= 100)
		return (size / 5);
	else
		return (size / 10);
}

/**
 * Moves elements from stack_a to stack_b that fall within a specified range,
 * determined by the chunk size and index.
 *
 * @param stack_a A pointer to the pointer of the head of stack_a.
 * @param stack_b A pointer to the pointer of the head of stack_b.
 * @param size The size of each chunk, used to determine the range.
 * @param index The current chunk index, used to calculate min and max values.
 */
void	push_to_stack_b(t_list **stack_a, t_list **stack_b, int size, int index)
{
	int	min_value;
	int	max_value;

	min_value = index * size;
	max_value = (index + 1) * size;
	while (elements_in_range(*stack_a, min_value, max_value))
	{
		if ((*stack_a)->value >= min_value && (*stack_a)->value < max_value)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

/**
 * Checks if there are any elements in the stack with values
 * within the specified range [min, max).
 *
 * @param stack The linked list stack to be checked.
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (exclusive).
 * @return 1 if there is at least one element in the range, 0 otherwise.
 */
int	elements_in_range(t_list *stack, int min, int max)
{
	while (stack)
	{
		if (stack->value >= min && stack->value < max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * Sort the stack_b by pushing its max element to stack_a
 *
 * @param stack_a The stack_a
 * @param stack_b The stack_b
 */
void	sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	max_value;

	while (*stack_b)
	{
		max_value = find_max_value(*stack_b);
		bring_to_top(stack_b, max_value, 'b');
		pa(stack_a, stack_b);
	}
}
