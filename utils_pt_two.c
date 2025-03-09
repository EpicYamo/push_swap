/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:33:34 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/08 23:27:04 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

char	*ft_order_args(char *args)
{
	int		i;
	int		digit_flag;
	char	*args_format;
	int		s;

	ft_initialize_vars(&s, &i, &digit_flag);
	args_format = malloc(sizeof(char) * (ft_order_args_pt_two(args) + 1));
	if (!args_format)
		return (NULL);
	while (args[i])
	{
		if (args[i] != ' ')
			digit_flag = 1;
		else if ((args[i] == ' ') && (digit_flag == 1))
		{
			args_format[s++] = ' ';
			digit_flag = 0;
		}
		if (digit_flag == 1)
			args_format[s++] = args[i];
		i++;
	}
	digit_flag = !digit_flag;
	args_format[s - digit_flag] = '\0';
	return (args_format);
}

int	ft_order_args_pt_three(char *args)
{
	int		i;
	int		digit_flag;
	int		space_count;
	int		digit_count;

	i = 0;
	digit_flag = 0;
	digit_count = 0;
	space_count = 0;
	while (args[i])
	{
		if (args[i] != ' ')
		{
			digit_count++;
			digit_flag = 1;
		}
		else if ((args[i] == ' ') && (digit_flag == 1))
		{
			space_count++;
			digit_flag = 0;
		}
		i++;
	}
	return (digit_count + space_count);
}

int	ft_order_args_pt_two(char *args)
{
	int	result;
	int	i;

	result = ft_order_args_pt_three(args);
	i = 0;
	while (args[i])
		i++;
	if (args[i - 1] == ' ')
		result--;
	return (result);
}

void	ft_initialize_vars(int *s, int *i, int *digit_flag)
{
	*s = 0;
	*i = 0;
	*digit_flag = 0;
}

int	ft_get_val(char *args_format, int which_one)
{
	int	space_counter;
	int	start;
	int	end;

	start = 0;
	space_counter = 0;
	while ((args_format[start]) && (space_counter != (which_one - 1)))
	{
		if (args_format[start] == ' ')
			space_counter++;
		start++;
	}
	space_counter = 0;
	end = start;
	while ((args_format[end]) && ((space_counter != 1)))
	{
		if (args_format[end] == ' ')
			space_counter++;
		end++;
	}
	if (space_counter == 0)
		return (ft_get_val_pt_two(args_format, start, end - 1));
	else
		return (ft_get_val_pt_two(args_format, start, end - 2));
}
