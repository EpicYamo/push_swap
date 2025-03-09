/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:46:11 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/09 18:52:25 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_is_digit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}

int	ft_number_count(int argc, char **argv)
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

int	ft_get_digit(int argc, char **argv, int which_one)
{
	int		val;
	char	*args;
	char	*args_format;

	val = 0;
	args = ft_create_args(argc, argv);
	if (!args)
		return (0);
	args_format = ft_order_args(args);
	free(args);
	if (!args_format)
		return (0);
	val = ft_get_val(args_format, which_one);
	free(args_format);
	return (val);
}

char	*ft_create_args(int argc, char **argv)
{
	char	*args;
	int		i;
	int		j;
	int		s;
	int		malloc_size;

	i = 1;
	s = 0;
	malloc_size = 0;
	while (argv[i])
		malloc_size += (ft_strlen(argv[i++]) + 1);
	i = 1;
	args = malloc(sizeof(char) * (malloc_size));
	if (!args)
		return (NULL);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			args[s++] = argv[i][j++];
		args[s++] = ' ';
		i++;
	}
	args[s - 1] = '\0';
	return (args);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
