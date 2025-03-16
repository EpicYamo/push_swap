/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:48:36 by aaycan            #+#    #+#             */
/*   Updated: 2025/03/15 09:59:41 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	long long		value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}t_list;

void		ft_error_check(int argc, char **argv);
void		ft_check_sign_and_digit(char *arg, int *sign_flag, int *digit_flag);
void		ft_error_check_repeated_numbers(t_list *stack);
t_list		*ft_set_list(char **argv);
long long	ft_get_digit(char **argv, int which_one);
int			ft_order_args_pt_three(char *args);
long long	ft_get_val(char *args_format, int which_one);
void		ft_write_error(void);
int			ft_is_digit(char d);
int			ft_strlen(char *str);
void		ft_free_list(t_list *head_node);
int			ft_list_len(t_list *list);
t_list		*ft_find_max(t_list *list);
t_list		*ft_find_min(t_list *list);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		ft_engine(t_list **stack_a, t_list **stack_b);
void		ft_set_vars_a(t_list *stack_a, t_list *stack_b);
void		ft_init_index(t_list *stack);
void		ft_init_target_a(t_list *stack_a, t_list *stack_b);
void		ft_init_cost_a(t_list *stack_a, t_list *stack_b);
void		ft_init_cheapest(t_list *stack);
void		ft_pass_a_to_b(t_list **stack_a, t_list **stack_b);
t_list		*ft_get_cheapest(t_list *stack);
void		ft_rotate_both(t_list **stack_a, t_list **stack_b,
				t_list *cheapest_node);
void		ft_rev_rotate_both(t_list **stack_a, t_list **stack_b,
				t_list *cheapest_node);
void		ft_push_prep(t_list **stack, t_list *top_node, int option);
void		ft_init_target_b(t_list *stack_a, t_list *stack_b);
void		ft_set_vars_b(t_list *stack_a, t_list *stack_b);
void		ft_pass_b_to_a(t_list **stack_a, t_list **stack_b);

#endif