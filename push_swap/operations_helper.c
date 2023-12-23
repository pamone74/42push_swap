/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:09:03 by pamone            #+#    #+#             */
/*   Updated: 2023/11/29 14:09:03 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack == NULL);
}

int	ft_pop(t_stack_b **headRef)
{
	t_stack_b		*current;
	int				temp;

	current = *headRef;
	temp = current->data;
	*headRef = current->link;
	free (current);
	return (temp);
}

int	ft_pop_a(t_stack **headref)
{
	t_stack		*current;
	int			temp;

	current = *headref;
	temp = current->data;
	*headref = current->link;
	free (current);
	return (temp);
}

t_stack	*get_bottom_a(t_stack *temp)
{
	t_stack	*stack_a;

	stack_a = temp;
	while (stack_a->link != NULL)
	{
		stack_a = stack_a->link;
	}
	return (stack_a);
}

t_stack_b	*get_bottom_b(t_stack_b *stack_b)
{
	while (stack_b->link != NULL)
	{
		stack_b = stack_b->link;
	}
	return (stack_b);
}
