/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:56:35 by hdelacou          #+#    #+#             */
/*   Updated: 2024/12/17 19:07:59 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = first->next;
		first->next = NULL;
		temp = *stack_a;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = first->next;
		first->next = NULL;
		temp = *stack_b;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
