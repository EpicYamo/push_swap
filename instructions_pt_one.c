/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pt_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:15:50 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/15 09:07:33 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	ft_sx(t_list **stack)
{
	t_list	*stack_tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	if (*stack && (*stack)->next)
	{
		stack_tmp = *stack;
		*stack = (*stack)->next;
		stack_tmp->next = (*stack)->next;
		(*stack)->next = stack_tmp;
		stack_tmp->prev = (*stack);
		if (stack_tmp->next)
			stack_tmp->next->prev = stack_tmp;
		(*stack)->prev = NULL;
	}
}

void	sa(t_list **stack_a)
{
	ft_sx(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	ft_sx(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_sx(stack_a);
	ft_sx(stack_b);
	write(1, "ss\n", 3);
}
