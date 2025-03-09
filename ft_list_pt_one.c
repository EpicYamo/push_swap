/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pt_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:33:26 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/09 18:46:39 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*ft_set_list(int argc, char **argv)
{
	int		digit_count;
	t_list	*head_node;
	t_list	*current_node;
	int		i;

	digit_count = ft_number_count(argc, argv);
	head_node = ft_create_head_node(argc, argv);
	current_node = head_node;
	i = 2;
	while (i <= digit_count)
	{
		ft_add_node(current_node, argc, argv, i, head_node);
		current_node = current_node->next;
		i++;
	}
	return (head_node);
}

t_list	*ft_create_head_node(int argc, char **argv)
{
	t_list	*head_node;

	head_node = malloc(sizeof(t_list));
	if (!head_node)
		exit(1);
	head_node->prev = NULL;
	head_node->value = ft_get_digit(argc, argv, 1);
	head_node->next = NULL;
	return (head_node);
}

void	ft_add_node(t_list *current_node, int argc, char **argv, int index, t_list *head_node)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		ft_free_list(head_node);
		exit(1);
	}
	new_node->value = ft_get_digit(argc, argv, index);
	new_node->prev = current_node;
	new_node->next = NULL;
	current_node->next = new_node;
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
