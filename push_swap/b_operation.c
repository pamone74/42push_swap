/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:32:38 by pamone            #+#    #+#             */
/*   Updated: 2023/11/29 03:32:38 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack_b *stack_b, int flag)
{
	if (stack_b->link == NULL || stack_b == NULL)
		return ;
	else
		ft_swap(&stack_b->data, &stack_b->link->data);
	if (flag)
		ft_putstr("sb");
}

void	ft_ss(t_stack *stack_a, t_stack_b *stack_b, int flag)
{
	ft_sa(stack_a, flag);
	ft_sb(stack_b, flag);
	if (flag)
		ft_putstr("ss");
}

void	ft_pb(t_stack **stack_a, t_stack_b **stack_b, int flag)
{
	t_stack		*new_node;
	int			item;

	new_node = *stack_a;
	if (new_node == NULL)
		return ;
	item = ft_pop_a(stack_a);
	ft_push_b(stack_b, item);
	if (flag)
		ft_putstr("pb");
}

void	ft_rb(t_stack_b **stack_b, int flag)
{
	t_stack_b	*temp;
	t_stack_b	*tail;

	if ((*stack_b) == NULL || !(*stack_b)->link)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->link;
	temp->link = NULL;
	tail = get_bottom_b(*stack_b);
	tail->link = temp;
	if (flag)
		ft_putstr("rb");
}

void	ft_rr(t_stack **stack_a, t_stack_b **stack_b, int flag)
{
	ft_ra(stack_a, flag);
	ft_rb(stack_b, flag);
}
