/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:40:48 by hdelacou          #+#    #+#             */
/*   Updated: 2024/12/19 16:38:16 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

// Fonctions de manipulation de piles
void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);

void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content);
t_list				*init_stack(int argc, char **argv);
int					find_max_value(t_list *stack);
int					main(int argc, char **argv);

void				turksort(t_list **stack_a, t_list **stack_b);
int					calculate_chunk_size(t_list *stack);
void				push_to_stack_b(t_list **stack_a, t_list **stack_b,
						int size, int index);
int					elements_in_range(t_list *stack, int min, int max);
void				sort_stack_b(t_list **stack_a, t_list **stack_b);

void				bring_to_top(t_list **stack, int value, char stack_name);
void				rotate(t_list **stack, char stack_name);
void				reverse_rotate(t_list **stack, char stack_name);
int					find_position(t_list *stack, int value);
void				finalize_sort(t_list **stack_a);

void				free_stack(t_list **stack);
int					ft_lstsize(t_list *stack);
int					no_duplicates(t_list *stack);
int					ft_isnumber(char *str);

void				sort_three(t_list **stack_a);
void				sort_five(t_list **stack_a, t_list **stack_b);
int					is_sorted(t_list *stack);
int					find_min_value(t_list *stack);
