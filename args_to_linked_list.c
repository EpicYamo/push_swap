/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:33:26 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/18 00:09:25 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int		ft_number_count(char **argv);
static t_list	*ft_create_head_node(char **argv);
static int		ft_add_node(t_list *current_node, char **argv,
					int index, t_list *head_node);

t_list	*ft_set_list(char **argv)
{
	int		digit_count;
	t_list	*head_node;
	t_list	*current_node;
	int		i;

	digit_count = ft_number_count(argv);
	head_node = ft_create_head_node(argv);
	current_node = head_node;
	i = 2;
	while (i <= digit_count)
	{
		if (ft_add_node(current_node, argv, i, head_node) == -1)
			ft_error_exit(head_node);
		current_node = current_node->next;
		i++;
	}
	return (head_node);
}

static int	ft_number_count(char **argv)
{
	int	i;
	int	j;
	int	count_of_numbers;
	int	number_flag;

	count_of_numbers = 0;
	i = 1;
	while (argv[i])
	{
		number_flag = 0;
		j = 0;
		while (argv[i][j])
		{
			if ((number_flag == 0) && (argv[i][j] != ' '))
			{
				number_flag = 1;
				count_of_numbers += 1;
			}
			else if (argv[i][j] == ' ')
				number_flag = 0;
			j += 1;
		}
		i += 1;
	}
	return (count_of_numbers);
}

static t_list	*ft_create_head_node(char **argv)
{
	t_list	*head_node;

	head_node = malloc(sizeof(t_list));
	if (!head_node)
		exit(EXIT_FAILURE);
	head_node->prev = NULL;
	head_node->next = NULL;
	head_node->target = NULL;
	head_node->index = 0;
	head_node->push_cost = 0;
	head_node->above_median = 0;
	head_node->cheapest = 0;
	head_node->value = ft_get_digit(argv, 1, head_node);
	return (head_node);
}

static int	ft_add_node(t_list *current_node, char **argv,
						int index, t_list *head_node)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (-1);
	current_node->next = new_node;
	new_node->prev = current_node;
	new_node->next = NULL;
	new_node->target = NULL;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = 0;
	new_node->cheapest = 0;
	new_node->value = ft_get_digit(argv, index, head_node);
	return (0);
}
