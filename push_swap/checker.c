/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:15:36 by pamone            #+#    #+#             */
/*   Updated: 2023/12/23 13:51:34 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (((*s1 != '\n') || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char)*s2);
		s1 ++;
		s2 ++;
	}
	return (0);
}

int	ft_comapare_command(char *cml, t_stack **stack_a, t_stack_b **stack_b)
{
	if (ft_strcmp(cml, "pa") == 0)
		ft_pa(stack_a, stack_b, 0);
	if (ft_strcmp(cml, "sa") == 0)
		ft_sa(*stack_a, 0);
	if (ft_strcmp(cml, "ra") == 0)
		ft_ra(stack_a, 0);
	if (ft_strcmp(cml, "rra") == 0)
		ft_rra(stack_a, 0);
	if (ft_strcmp(cml, "pb") == 0)
		ft_pb(stack_a, stack_b, 0);
	if (ft_strcmp(cml, "rb") == 0)
		ft_rb(stack_b, 0);
	if (ft_strcmp(cml, "rrb") == 0)
		ft_rrb(stack_b, 0);
	if (ft_strcmp(cml, "sb") == 0)
		ft_sb(*stack_b, 0);
	if (ft_strcmp(cml, "ss") == 0)
		ft_ss(*stack_a, *stack_b, 0);
	if (ft_strcmp(cml, "rrr") == 0)
		ft_rrr(stack_b, stack_a, 0);
	if (ft_strcmp(cml, "ss") == 0)
		ft_ss(*stack_a, *stack_b, 0);
	return (1);
}

void	ft_print(t_stack **stack_a, t_stack_b **stack_b)
{
	if (!ft_is_sorted(*stack_a) && *stack_b == NULL)
		ft_putstr("OK");
	else
		ft_putstr("KO");
}

void	ft_checker_helper(t_stack **stack_a, t_stack_b **stack_b)
{
	char	*cml;

	cml = get_next_line(0);
	if (stack_a)
	{
		while (cml && cml[0] != '\0')
		{
			ft_comapare_command(cml, stack_a, stack_b);
			free(cml);
			cml = get_next_line(0);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack_b	*stack_b;

	if (argc < 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_std_out(argv[1], "") == 0)
	{
		ft_error();
		return (0);
	}
	ft_parse(&stack_a, argv);
	if (!ft_duplicate(stack_a))
	{
		ft_checker_helper(&stack_a, &stack_b);
		ft_print(&stack_a, &stack_b);
	}
	else
		ft_error();
	ft_free_stack(stack_a);
	free(stack_b);
}
