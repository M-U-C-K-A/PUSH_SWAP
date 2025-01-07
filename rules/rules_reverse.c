/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:57:54 by hdelacou          #+#    #+#             */
/*   Updated: 2024/12/17 19:08:15 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	last = *stack_a;
	second_last = NULL;
	if (*stack_a && (*stack_a)->next)
	{
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*second_last;

	last = *stack_b;
	second_last = NULL;
	if (*stack_b && (*stack_b)->next)
	{
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
