/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_pt_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:44:09 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/12 19:44:09 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_init_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_list_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i += 1;
	}
}

void	ft_init_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list		*b_tmp;
	t_list		*target_node;
	long long	target_val;

	while (stack_a)
	{
		target_val = LONG_MIN;
		b_tmp = stack_b;
		while (b_tmp)
		{
			if (b_tmp->value < stack_a->value
				&& b_tmp->value > target_val)
			{
				target_val = b_tmp->value;
				target_node = b_tmp;
			}
			b_tmp = b_tmp->next;
		}
		if (target_val == LONG_MIN)
			stack_a->target = ft_find_max(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

void	ft_init_cost_a(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_list_len(stack_a);
	len_b = ft_list_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - stack_a->index;
		if (stack_a->target->above_median)
			stack_a->push_cost += stack_a->target->index;
		else
			stack_a->push_cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	ft_init_cheapest(t_list *stack)
{
	t_list		*cheapest_node;
	long long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_node = stack;
			cheapest_value = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
