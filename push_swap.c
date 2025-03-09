/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:47:12 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/06 21:47:12 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	ft_error_check(argc, argv);
	stack_a = ft_set_list(argc, argv);
	if (ft_error_check_pt_three(stack_a) == 1)
	{
		ft_free_list(stack_a);
		ft_write_error();
	}
	ft_print_list(stack_a);
	ft_free_list(stack_a);
	return (0);
}
