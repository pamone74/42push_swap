/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:16:33 by pamone            #+#    #+#             */
/*   Updated: 2023/11/29 14:16:33 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack_a, int flag)
{
	if (ft_count_node(stack_a) == 1 || stack_a == NULL)
		return ;
	else
		ft_swap(&stack_a->data, &stack_a->link->data);
	if (flag)
		ft_putstr("sa");
}

void	ft_pa(t_stack **stack_a, t_stack_b **stack_b, int flag)
{
	int				item;
	t_stack_b		*new_node;

	new_node = *stack_b;
	if (new_node == NULL)
		return ;
	item = ft_pop(stack_b);
	ft_push(stack_a, item);
	if (flag)
		ft_putstr("pa");
}

void	ft_ra(t_stack **stack_a, int flag)
{
	t_stack	*temp;
	t_stack	*tail;

	if ((*stack_a) == NULL || !(*stack_a)->link)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->link;
	temp->link = NULL;
	tail = get_bottom_a(*stack_a);
	tail->link = temp;
	if (flag)
		ft_putstr("ra");
}

void	ft_rra(t_stack **stack_a, int flag)
{
	int	len;

	len = ft_count_node(*stack_a);
	while (--len)
	{
		ft_ra(stack_a, 0);
	}
	if (flag)
		ft_putstr("rra");
}

void	ft_rrb(t_stack_b **stack_a, int flag)
{
	int	len;

	len = ft_count_node_b(*stack_a);
	while (--len)
	{
		ft_rb(stack_a, 0);
	}
	if (flag)
		ft_putstr("rra");
}
