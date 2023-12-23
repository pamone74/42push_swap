/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:53:29 by pamone            #+#    #+#             */
/*   Updated: 2023/12/16 00:53:29 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_two(t_stack **stack_a)
{
	ft_sa(*stack_a, 1);
	ft_ra(stack_a, 1);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	last;

	top = (*stack_a)->data;
	middle = (*stack_a)->link->data;
	last = (*stack_a)->link->link->data;
	if (ft_is_sorted(*stack_a))
	{
		if (top < middle && last > top)
			ft_op_two(stack_a);
		else if (top > middle && middle > last)
		{
			ft_ra(stack_a, 1);
			ft_sa(*stack_a, 1);
		}
		else if (top > middle && top > last)
			ft_ra(stack_a, 1);
		else if (top < last && middle < last)
			ft_sa(*stack_a, 1);
		else if (top < middle && middle > last)
			ft_rra(stack_a, 1);
	}
}

void	ft_sort_four(t_stack **stack_a)
{
	t_stack_b	*stack_b;
	int			min;

	stack_b = NULL;
	if (!ft_is_sorted(*stack_a))
		return ;
	min = ft_stack_a_min(*stack_a);
	if (ft_get_index(*stack_a, min) == 1)
		ft_sa(*stack_a, 1);
	else if (ft_get_index(*stack_a, min) == 2)
		ft_call(ft_rra, stack_a, 2);
	else if (ft_get_index(*stack_a, min) == 3)
		ft_rra(stack_a, 1);
	ft_pb(stack_a, &stack_b, 1);
	ft_sort_three(stack_a);
	ft_pa(stack_a, &stack_b, 1);
}

void	ft_sort_five(t_stack **stack_a)
{
	t_stack_b	*stack_b;
	int			min;

	stack_b = NULL;
	if (!ft_is_sorted(*stack_a))
		return ;
	min = ft_stack_a_min(*stack_a);
	if (ft_get_index(*stack_a, min) == 1)
		ft_sa(*stack_a, 1);
	else if (ft_get_index(*stack_a, min) == 2)
		ft_call(ft_ra, stack_a, 2);
	else if (ft_get_index(*stack_a, min) == 3)
		ft_call(ft_rra, stack_a, 2);
	else if (ft_get_index(*stack_a, min) == 4)
		ft_rra(stack_a, 1);
	ft_pb(stack_a, &stack_b, 1);
	ft_sort_four(stack_a);
	ft_pa(stack_a, &stack_b, 1);
}

void	ft_sort_six(t_stack **stack_a)
{
	t_stack_b	*stack_b;
	int			min;

	stack_b = NULL;
	if (!ft_is_sorted(*stack_a))
		return ;
	min = ft_stack_a_min(*stack_a);
	if (ft_get_index(*stack_a, min) == 1)
		ft_sa(*stack_a, 1);
	else if (ft_get_index(*stack_a, min) == 2)
		ft_call(ft_ra, stack_a, 2);
	else if (ft_get_index(*stack_a, min) == 3)
		ft_call(ft_rra, stack_a, 3);
	else if (ft_get_index(*stack_a, min) == 4)
		ft_call(ft_rra, stack_a, 2);
	else if (ft_get_index(*stack_a, min) == 5)
		ft_rra(stack_a, 1);
	ft_pb(stack_a, &stack_b, 1);
	ft_sort_five(stack_a);
	ft_pa(stack_a, &stack_b, 1);
}
