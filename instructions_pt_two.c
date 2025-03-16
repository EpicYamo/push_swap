/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pt_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:51:25 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/15 09:07:19 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*replace_b;

	replace_b = NULL;
	if (!*stack_b)
		return ;
	if ((*stack_b)->next)
	{
		(*stack_b)->next->prev = NULL;
		replace_b = (*stack_b)->next;
	}
	(*stack_b)->next = *stack_a;
	if ((*stack_a))
		(*stack_a)->prev = *stack_b;
	*stack_a = *stack_b;
	if (replace_b)
		*stack_b = replace_b;
	else
		*stack_b = NULL;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*replace_a;

	replace_a = NULL;
	if (!*stack_a)
		return ;
	if ((*stack_a)->next)
	{
		(*stack_a)->next->prev = NULL;
		replace_a = (*stack_a)->next;
	}
	(*stack_a)->next = *stack_b;
	if ((*stack_b))
		(*stack_b)->prev = *stack_a;
	*stack_b = *stack_a;
	if (replace_a)
		*stack_a = replace_a;
	else
		*stack_a = NULL;
	write(1, "pb\n", 3);
}
