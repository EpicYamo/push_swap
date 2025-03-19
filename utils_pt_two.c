/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:58:30 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/18 00:11:28 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

t_list	*ft_find_max(t_list *list)
{
	t_list		*tmp;
	long long	i;

	i = LONG_MIN;
	while (list)
	{
		if (list->value > i)
		{
			i = list->value;
			tmp = list;
		}
		list = list->next;
	}
	return (tmp);
}

t_list	*ft_find_min(t_list *list)
{
	t_list		*tmp;
	long long	i;

	i = LONG_MAX;
	while (list)
	{
		if (list->value < i)
		{
			i = list->value;
			tmp = list;
		}
		list = list->next;
	}
	return (tmp);
}

void	ft_free_list(t_list *head_node)
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = head_node;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}

void	ft_error_exit(t_list *head_node)
{
	ft_free_list(head_node);
	exit(EXIT_FAILURE);
}
