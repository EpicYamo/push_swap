/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers_pt_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:16:03 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/17 23:43:28 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_error_check_pt_two(char **argv);
static void	ft_error_check_pt_three(char **argv);
static void	ft_error_check_pt_four(char **argv);

void	ft_error_check(int argc, char **argv)
{
	int	i;
	int	j;

	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		exit(EXIT_FAILURE);
	ft_error_check_pt_two(argv);
	ft_error_check_pt_three(argv);
	ft_error_check_pt_four(argv);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ' || argv[i][j] == '\t'
				|| argv[i][j] == '-' || argv[i][j] == '+')
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
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	ft_error_check_pt_two(char **argv)
{
	int	i;
	int	j;
	int	digit_flag;

	i = 1;
	while (argv[i])
	{
		digit_flag = 0;
		j = 0;
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

static void	ft_error_check_pt_three(char **argv)
{
	int	i;
	int	sign_flag;
	int	digit_flag;

	i = 1;
	while (argv[i])
	{
		sign_flag = 0;
		digit_flag = 0;
		ft_check_sign_and_digit(argv[i], &sign_flag, &digit_flag);
		i++;
	}
}

static void	ft_error_check_pt_four(char **argv)
{
	int	i;
	int	j;
	int	num_length;

	i = 1;
	while (argv[i])
	{
		num_length = 0;
		j = 0;
		while (argv[i][j])
		{
			if ((num_length == 0) && (argv[i][j] == '0'))
				while (argv[i][j] == '0')
					j++;
			if (ft_is_digit(argv[i][j]))
				num_length++;
			else if (ft_is_digit(argv[i][j]) == 0)
				num_length = 0;
			j++;
		}
		if (num_length > 11)
			ft_write_error();
		i++;
	}
}
