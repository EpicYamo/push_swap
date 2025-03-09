/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:46:41 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/06 21:46:41 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_error_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_error_check_pt_two(argc, argv);
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j += 1;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
			else if (ft_is_digit(argv[i][j]) != 1)
				ft_write_error();
			else
				j++;
		}
		i++;
	}
}

void	ft_write_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_check_pt_two(int argc, char **argv)
{
	int	i;
	int	j;
	int	digit_flag;

	i = 1;
	while (argv[i])
	{
		digit_flag = 0;
		j = 0;
		if (argv[i][0] == '\0')
			ft_write_error();
		while (argv[i][j])
		{
			if (ft_is_digit(argv[i][j]))
				digit_flag = 1;
			j++;
		}
		if (digit_flag == 0)
			ft_write_error();
		i++;
	}
}

int	ft_error_check_pt_three(t_list *stack)
{
	int		tmp;
	t_list	*stack_clone;
	int		flag;

	stack_clone = stack;
	while ((stack))
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
				return (1);
		}
		stack = stack->next;
	}
	return (0);
}
