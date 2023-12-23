/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_radix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:27:23 by pamone            #+#    #+#             */
/*   Updated: 2023/12/16 15:25:51 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_radix_pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	if (flag)
		ft_putstr("pa");
	return (0);
}

int	ft_radix_pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	if (flag)
		ft_putstr("pb");
	return (0);
}

int	ft_radix_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_count_node(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_stack_end(head);
	*stack = head->link;
	head->link = NULL;
	tail->link = head;
	return (0);
}

int	ft_radix_ra(t_stack **stack_a, int flag)
{
	if (ft_radix_rotate(stack_a) == -1)
		return (-1);
	if (flag)
		ft_putstr("ra");
	return (0);
}

void	ft_rrr(t_stack_b **stack_b, t_stack **stack_a, int flag)
{
	ft_rra(stack_a, flag);
	ft_rrb(stack_b, flag);
}
