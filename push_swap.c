/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:47:12 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/12 21:57:36 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	ft_error_check(argc, argv);
	stack_a = ft_set_list(argv);
	stack_b = NULL;
	ft_error_check_repeated_numbers(stack_a);
	ft_engine(&stack_a, &stack_b);
	ft_free_list(stack_a);
	exit(EXIT_SUCCESS);
}
