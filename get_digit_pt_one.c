/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_pt_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:31:31 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/18 00:11:58 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdlib.h"

static char	*ft_create_args(char **argv);
static char	*ft_order_args(char *args);
static void	ft_initialize_vars(int *s, int *i, int *digit_flag);
static int	ft_order_args_pt_two(char *args);

long long	ft_get_digit(char **argv, int which_one, t_list *head_node)
{
	long long	val;
	char		*args;
	char		*args_format;

	val = 0;
	args = ft_create_args(argv);
	if (!args)
		ft_error_exit(head_node);
	args_format = ft_order_args(args);
	free(args);
	if (!args_format)
		ft_error_exit(head_node);
	val = ft_get_val(args_format, which_one);
	free(args_format);
	if (val == 42000000000)
		ft_error_exit(head_node);
	return (val);
}

static char	*ft_create_args(char **argv)
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

static char	*ft_order_args(char *args)
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

static void	ft_initialize_vars(int *s, int *i, int *digit_flag)
{
	*s = 0;
	*i = 0;
	*digit_flag = 0;
}

static int	ft_order_args_pt_two(char *args)
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
