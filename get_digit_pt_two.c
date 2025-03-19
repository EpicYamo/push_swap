/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_pt_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:38:06 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/18 00:04:35 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static long long	ft_get_val_pt_two(char *args_format, int start, int end);
static long long	ft_atoi(const char *str);
static int			ft_isspacemod(int *i, const char *strwosp);

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

long long	ft_get_val(char *args_format, int which_one)
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

static long long	ft_get_val_pt_two(char *args_format, int start, int end)
{
	long long	val;
	int			i;
	char		*number;

	i = 0;
	number = malloc(sizeof(char) * (end - start + 2));
	if (!number)
		return (42000000000);
	while (args_format[start] && (start <= end))
	{
		number[i] = args_format[start];
		i++;
		start++;
	}
	number[i] = '\0';
	val = ft_atoi(number);
	free(number);
	return (val);
}

static long long	ft_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	strg;

	sign = 1;
	strg = 0;
	i = 0;
	ft_isspacemod(&i, str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		strg = (10 * strg) + (str[i] - '0');
		i++;
	}
	return (strg * sign);
}

static int	ft_isspacemod(int *i, const char *strwosp)
{
	while (strwosp[*i] == '\t' || strwosp[*i] == '\n' || strwosp[*i] == '\v'
		|| strwosp[*i] == '\f' || strwosp[*i] == '\r' || strwosp[*i] == ' ')
	{
		(*i)++;
	}
	return (*i);
}
