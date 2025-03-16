/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pt_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:02:01 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/15 09:07:21 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	ft_rx(t_list **stack)
{
	t_list	*last;
	t_list	*head_tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	head_tmp = *stack;
	last = *stack;
	while (last && last->next)
		last = last->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	head_tmp->next = NULL;
	last->next = head_tmp;
	head_tmp->prev = last;
}

void	ra(t_list **stack_a)
{
	ft_rx(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	ft_rx(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
	write(1, "rr\n", 3);
}
