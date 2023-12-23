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

int	main(int ac, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		if (ft_std_out(argv[1], "") == 0)
		{
			ft_error();
			return (0);
		}
		ft_parse(&stack_a, argv);
		if (ft_is_sorted(stack_a) && !ft_duplicate(stack_a))
			ft_sort_num(&stack_a, &stack_b);
		else if (ac == 2 || !ft_is_sorted(stack_a))
			return (0);
		else
			ft_error();
		ft_free_stack(stack_a);
		return (1);
	}
	free(stack_a);
	free(stack_b);
}
