/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_pt_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:34:01 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/14 18:53:37 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_vars_a(t_list *stack_a, t_list *stack_b)
{
	ft_init_index(stack_a);
	ft_init_index(stack_b);
	ft_init_target_a(stack_a, stack_b);
	ft_init_cost_a(stack_a, stack_b);
	ft_init_cheapest(stack_a);
}

void	ft_pass_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = ft_get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		ft_rev_rotate_both(stack_a, stack_b, cheapest_node);
	ft_push_prep(stack_a, cheapest_node, 1);
	ft_push_prep(stack_b, cheapest_node->target, 2);
	pb(stack_a, stack_b);
}

void	ft_set_vars_b(t_list *stack_a, t_list *stack_b)
{
	ft_init_index(stack_a);
	ft_init_index(stack_b);
	ft_init_target_b(stack_a, stack_b);
}

void	ft_pass_b_to_a(t_list **stack_a, t_list **stack_b)
{
	ft_push_prep(stack_a, (*stack_b)->target, 1);
	pa(stack_a, stack_b);
}
