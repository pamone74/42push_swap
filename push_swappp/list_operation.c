/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:51:15 by pamone            #+#    #+#             */
/*   Updated: 2023/12/03 12:51:15 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_a_min(t_stack *stack_a)
{
	int		i;
	t_stack	*temp;

	temp = stack_a;
	i = temp->data;
	while (temp)
	{
		if (temp->data < i)
			i = temp->data;
		temp = temp->link;
	}
	return (i);
}

int	ft_stack_a_max(t_stack *stack_a)
{
	int		i;

	i = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > i)
			i = stack_a->data;
		stack_a = stack_a->link;
	}
	return (i);
}

int	push(t_stack **to, t_stack **from)
{
	t_stack	*tmp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_count_node(*from) == 0)
		return (-1);
	head_to = *to;
	head_from = *from;
	tmp = head_from;
	head_from = head_from->link;
	*from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->link = NULL;
		*to = head_to;
	}
	else
	{
		tmp->link = head_to;
		*to = tmp;
	}
	return (0);
}

int	ft_get_index(t_stack *stack, int item)
{
	int	i;

	if (stack != NULL)
	{
		i = 0;
		while (stack)
		{
			if (stack->data == item)
				return (i);
			stack = stack->link;
			i++;
		}
	}
	return (0);
}

int	ft_bit_max(t_stack **stack_a)
{
	t_stack		*temp_node;
	int			max;
	int			bits;

	temp_node = *stack_a;
	max = temp_node->index;
	bits = 0;
	while (temp_node)
	{
		if (temp_node->index > max)
			max = temp_node->index;
		temp_node = temp_node->link;
	}
	while ((max >> bits) != 0)
		bits ++;
	return (bits);
}
