/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:34:53 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/09 18:34:53 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_list(t_list *head_node)
{
	t_list *current_node;

	current_node = head_node;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->value);
		current_node = current_node->next;
	}
}
