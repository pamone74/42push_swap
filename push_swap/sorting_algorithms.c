/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:52:31 by pamone            #+#    #+#             */
/*   Updated: 2023/12/02 10:52:31 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_b(t_stack_b *stack_b)
{
	while (stack_b->link != NULL)
	{
		if (stack_b->data < stack_b->link->data)
			return (0);
		stack_b = stack_b->link;
	}
	return (1);
}

void	ft_sort_three_b(t_stack_b **stack_a)
{
	int	top;
	int	middle;
	int	last;

	top = (*stack_a)->data;
	middle = (*stack_a)->link->data;
	last = (*stack_a)->link->link->data;
	if (ft_is_sorted_b(*stack_a))
		return ;
	if (top < middle && last > middle)
	{
		ft_rb(stack_a, 1);
		ft_sb(*stack_a, 1);
	}
	else if (top > middle && top > last)
	{
		ft_rrb(stack_a, 1);
		ft_sb(*stack_a, 1);
	}
	else if (top > middle && middle < last)
		ft_rrb(stack_a, 1);
	else if (top < middle && top < last)
		ft_rb(stack_a, 1);
	else if (top < middle && top > last)
		ft_sb(*stack_a, 1);
}

int	get_min(t_stack_b **stack)
{
	t_stack_b	*temp_node;
	int			min;

	temp_node = *stack;
	min = temp_node->data;
	while (temp_node != NULL)
	{
		if (temp_node->data < min)
			min = temp_node->data;
		temp_node = temp_node->link;
	}
	return (min);
}

void	ft_free_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->link;
		free(current);
		current = next;
	}
}

void	ft_sort_num(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_is_sorted(*stack_a))
		return ;
	if (ft_count_node(*stack_a) == 2)
		ft_sa(*stack_a, 1);
	else if (ft_count_node(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_count_node(*stack_a) == 4)
		ft_sort_four(stack_a);
	else if (ft_count_node(*stack_a) == 5)
		ft_sort_five(stack_a);
	else if (ft_count_node(*stack_a) == 6)
		ft_sort_six(stack_a);
	else
		ft_radix_sort(stack_a, stack_b);
}
