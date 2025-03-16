/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_pt_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:34:12 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/15 09:12:22 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_check(t_list *stack_a);
static void	ft_sort_three_num(t_list **stack_a);
static void	ft_sort_stack(t_list **stack_a, t_list **stack_b);
static void	ft_rearrange_min_max(t_list	**stack_a);

void	ft_engine(t_list **stack_a, t_list **stack_b)
{
	if (!ft_sort_check(*stack_a))
	{
		if (ft_list_len(*stack_a) == 2)
			sa(stack_a);
		else if (ft_list_len(*stack_a) == 3)
			ft_sort_three_num(stack_a);
		else
			ft_sort_stack(stack_a, stack_b);
	}
}

static int	ft_sort_check(t_list *stack_a)
{
	if (!(stack_a))
		return (1);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static void	ft_sort_three_num(t_list **stack_a)
{
	t_list	*max_value_node;

	max_value_node = ft_find_max(*stack_a);
	if (*stack_a == max_value_node)
		ra(stack_a);
	else if ((*stack_a)->next == max_value_node)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

static void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	length_a;

	length_a = ft_list_len(*stack_a);
	if (((length_a-- > 3) && !ft_sort_check(*stack_a)))
		pb(stack_a, stack_b);
	if (((length_a-- > 3) && !ft_sort_check(*stack_a)))
		pb(stack_a, stack_b);
	while ((length_a-- > 3) && !ft_sort_check(*stack_a))
	{
		ft_set_vars_a(*stack_a, *stack_b);
		ft_pass_a_to_b(stack_a, stack_b);
	}
	ft_sort_three_num(stack_a);
	while (*stack_b)
	{
		ft_set_vars_b(*stack_a, *stack_b);
		ft_pass_b_to_a(stack_a, stack_b);
	}
	ft_init_index(*stack_a);
	ft_rearrange_min_max(stack_a);
}

static void	ft_rearrange_min_max(t_list	**stack_a)
{
	while ((*stack_a)->value != ft_find_min(*stack_a)->value)
	{
		if (ft_find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
