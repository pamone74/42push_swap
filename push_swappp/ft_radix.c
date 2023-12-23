/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:29:24 by pamone            #+#    #+#             */
/*   Updated: 2023/12/16 15:45:21 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->link;
		}
	}
	return (min);
}

void	ft_assign_index(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = ft_get_min(stack);
	while (head)
	{
		head->index = index++;
		head = ft_get_min(stack);
	}
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	temp_node = *stack_a;
	size = ft_count_node(temp_node);
	max_bits = ft_bit_max(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			temp_node = *stack_a;
			if (((temp_node->index >> i) & 1) == 1)
				ft_radix_ra(stack_a, 1);
			else
				ft_radix_pb(stack_a, stack_b, 1);
		}
		while (ft_count_node(*stack_b) != 0)
			ft_radix_pa(stack_a, stack_b, 1);
		i++;
	}
}
