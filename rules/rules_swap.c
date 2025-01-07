/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:55:50 by hdelacou          #+#    #+#             */
/*   Updated: 2024/12/17 20:32:43 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = (*stack_a)->next;
	if (*stack_a && (*stack_a)->next)
	{
		first->next = second->next;
		second->next = first;
		*stack_a = second;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		second = (*stack_b)->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
