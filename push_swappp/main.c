/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:39 by pamone            #+#    #+#             */
/*   Updated: 2023/11/30 18:52:39 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_num(t_stack **stack_a, t_stack **stack_b)
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


int	main(int ac, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_parse(&stack_a, argv);
		if (ft_is_sorted(stack_a) && !ft_duplicate(stack_a))
			ft_sort_num(&stack_a, &stack_b);
		else
			ft_error();
		ft_free_stack(stack_a);
		return (1);
	}
	free(stack_a);
	free(stack_b);
}
