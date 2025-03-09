/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:48:36 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/09 18:35:28 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}t_list;

void	ft_error_check(int argc, char **argv);
void	ft_write_error(void);
int		ft_is_digit(char d);
int		ft_atoi(const char *str);
int		ft_isspacemod(int *i, const char *strwosp);
int		ft_number_count(int argc, char **argv);
void	ft_error_check_pt_two(int argc, char **argv);
int		ft_get_digit(int argc, char **argv, int which_one);
char	*ft_create_args(int argc, char **argv);
int		ft_strlen(char *str);
char	*ft_order_args(char *args);
int		ft_order_args_pt_two(char *args);
int		ft_order_args_pt_three(char *args);
void	ft_initialize_vars(int *s, int *i, int *digit_flag);
int		ft_get_val(char *args_format, int which_one);
int		ft_get_val_pt_two(char *args_format, int start, int end);
int		ft_error_check_pt_three(t_list *stack);
t_list	*ft_set_list(int argc, char **argv);
t_list	*ft_create_head_node(int argc, char **argv);
void	ft_add_node(t_list *current_node, int argc, char **argv, int index, t_list *head_node);
void	ft_free_list(t_list *head_node);

void	ft_print_list(t_list *head_node);

#endif