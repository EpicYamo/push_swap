/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers_pt_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:22:27 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/15 13:09:08 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_number_limits(t_list *stack);
static void	ft_check_sign_and_digit_pt_two(int *sign_flag, int *digit_flag);

void	ft_check_sign_and_digit(char *arg, int *sign_flag, int *digit_flag)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if ((arg[j] == ' ') || (arg[j] == '\t'))
		{
			if (*digit_flag == 0 && *sign_flag > 0)
				ft_write_error();
			*sign_flag = 0;
			*digit_flag = 0;
		}
		else if (ft_is_digit(arg[j]))
			ft_check_sign_and_digit_pt_two(sign_flag, digit_flag);
		else if ((arg[j] == '-') || (arg[j] == '+'))
		{
			*sign_flag += 1;
			if (*sign_flag > 1)
				ft_write_error();
		}
		j++;
	}
	if ((arg[j] == '\0'))
		if (*digit_flag == 0 && *sign_flag > 0)
			ft_write_error();
}

void	ft_error_check_repeated_numbers(t_list *stack)
{
	long long	tmp;
	t_list		*stack_clone;
	t_list		*stack_head;
	int			flag;

	ft_check_number_limits(stack);
	stack_head = stack;
	while (stack)
	{
		tmp = stack->value;
		stack_clone = stack;
		flag = 0;
		while ((stack_clone))
		{
			if (tmp == stack_clone->value)
				flag += 1;
			stack_clone = stack_clone->next;
			if (flag > 1)
			{
				ft_free_list(stack_head);
				ft_write_error();
			}
		}
		stack = stack->next;
	}
}

static void	ft_check_number_limits(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (current->value < -2147483648 || current->value > 2147483647)
		{
			ft_free_list(stack);
			ft_write_error();
		}
		current = current->next;
	}
}

static void	ft_check_sign_and_digit_pt_two(int *sign_flag, int *digit_flag)
{
	*digit_flag = 1;
	*sign_flag += 10;
}
