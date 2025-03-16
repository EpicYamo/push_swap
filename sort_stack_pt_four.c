/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_pt_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:08:17 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/15 10:03:45 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <limits.h>

t_list	*ft_get_cheapest(t_list *stack)
{
	t_list	*cheapest_node;

	cheapest_node = NULL;
	while (stack)
	{
		if (stack->cheapest == 1)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}

void	ft_rotate_both(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	ft_init_index(*stack_a);
	ft_init_index(*stack_b);
}

void	ft_rev_rotate_both(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	ft_init_index(*stack_a);
	ft_init_index(*stack_b);
}

void	ft_push_prep(t_list **stack, t_list *top_node, int option)
{
	while (*stack != top_node)
	{
		if (option == 1)
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (option == 2)
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	ft_init_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list		*a_tmp;
	t_list		*target_node;
	long long	target_val;

	while (stack_b)
	{
		target_val = LONG_MAX;
		a_tmp = stack_a;
		while (a_tmp)
		{
			if (a_tmp->value > stack_b->value
				&& a_tmp->value < target_val)
			{
				target_val = a_tmp->value;
				target_node = a_tmp;
			}
			a_tmp = a_tmp->next;
		}
		if (target_val == LONG_MAX)
			stack_b->target = ft_find_min(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}
