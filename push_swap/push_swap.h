/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:32:01 by pamone            #+#    #+#             */
/*   Updated: 2023/11/30 03:32:01 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int					data;
	int					index;
	struct s_stack		*link;
}						t_stack;

typedef struct s_stack_b
{
	int					data;
	int					index;
	struct s_stack_b	*link;
}						t_stack_b;

typedef void	(*t_call_many)(t_stack**, int);
t_stack_b	*append_node_b(t_stack_b **headref, int data);
t_stack_b	*get_bottom_b(t_stack_b *stack_b);
t_stack		*ft_get_min(t_stack **stack);
t_stack		*ft_stack_end(t_stack *head);
t_stack		*get_bottom_a(t_stack *stack_a);
void		ft_ra(t_stack **stack_a, int flag);
void		ft_sort_num(t_stack **stack_a, t_stack **stack_b);
void		ft_put_nbr(int n);
void		ft_ss(t_stack *stack_a, t_stack_b *stack_b, int flag);
void		ft_sa(t_stack *stack_a, int flag);
void		ft_pa(t_stack **stack_a, t_stack_b **stack_b, int flag);
void		ft_rra(t_stack **stack_a, int flag);
void		ft_rrb(t_stack_b **stack_b, int flag);
void		ft_sb(t_stack_b *stack_b, int flag);
void		ft_pb(t_stack **stack_a, t_stack_b **stack_b, int flag);
void		ft_rb(t_stack_b **stack_b, int flag);
void		ft_rr(t_stack **stack_a, t_stack_b **stack_b, int flag);
void		ft_push_b(t_stack_b **headref, int data);
void		ft_assign_index(t_stack **stack);
void		ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void		ft_parse(t_stack **stack_a, char *args[]);
void		ft_display(t_stack *stak);
void		ft_push(t_stack **head, int data);
void		ft_call(t_call_many func, t_stack **stack_a, int n);
void		ft_swap(int *item1, int *item2);
void		ft_putstr(char *str);
void		ft_sort_three(t_stack **stack_a);
void		ft_sort_four(t_stack **stack_a);
void		ft_sort_five(t_stack **stack_a);
void		ft_sort_six(t_stack **stack_a);
void		ft_stack_append(t_stack **stack, int data);
void		ft_rrr(t_stack_b **stack_b, t_stack **stack_a, int flag);
void		ft_error(void);
void		ft_free_stack(t_stack *head);
char		**ft_split(const char	*str, int c);
char		*ft_strjoin(char *arg[]);
int			ft_count_node(t_stack *head);
int			ft_bit_max(t_stack **stack_a);
int			ft_radix_pa(t_stack **stack_a, t_stack **stack_b, int flag);
int			ft_radix_pb(t_stack **stack_a, t_stack **stack_b, int flag);
int			ft_radix_ra(t_stack **stack_a, int flag);
int			ft_radix_rotate(t_stack **stack);
int			ft_count_node_b(t_stack_b *head);
int			ft_strlen(char *str);
int			push(t_stack **to, t_stack **from);
int			ft_get_index(t_stack *stack, int item);
int			ft_pop_a(t_stack **headref);
int			ft_pop(t_stack_b **headRef);
int			is_empty(t_stack *stack);
int			ft_duplicate(t_stack *stack_a);
int			ft_is_integer(int n);
int			ft_check_ascii(char *str);
int			ft_is_sorted(t_stack *stack_a);
int			ft_check_overflow(int n);
int			ft_atoi(const char *str);
int			ft_std_out(const char *s1, const char *s2);
int			ft_stack_a_min(t_stack *stack_a);
int			ft_valid_stdin(char *str);
int			ft_strcmp(const char *s1, const char *s2);
#endif