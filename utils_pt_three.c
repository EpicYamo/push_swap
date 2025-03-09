/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:07:48 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/08 23:43:26 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_get_val_pt_two(char *args_format, int start, int end)
{
	int		val;
	int		i;
	char	*number;

	i = 0;
	number = malloc(sizeof(char) * (end - start + 2));
	if (!number)
		return (0);
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
