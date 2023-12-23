/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:15:36 by pamone            #+#    #+#             */
/*   Updated: 2023/12/23 05:58:53 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>

int ft_is_whitespace(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        if((str[i] >= 9 && str[i] <= 13))
            return (1);
        i++;
    }
    return (0);
}
int	ft_strcmp(const char *s1, const char *s2)
{
	while (((*s1 != '\n' )|| *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return ((unsigned char) *s1 - (unsigned char)*s2);
		}
		s1 ++;
		s2 ++;
	}
	return (0);
}
int ft_comapare_command(char *cml, t_stack **stack_a, t_stack_b **stack_b)
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
        ft_pb(stack_a,stack_b, 0);
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

void    ft_print(t_stack **stack_a, t_stack_b **stack_b)
{
    
    if (!ft_is_sorted(*stack_a) && *stack_b == NULL)
        ft_putstr("OK");
    else
        ft_putstr("KO");
}

int main(int argc, char *argv[])
{
    t_stack     *stack_a;
    t_stack_b   *stack_b;
    char        *cml;

    if (argc > 1)
    {
        if(!(stack_a = (t_stack *)malloc(sizeof(t_stack))))
            return 0;
        if(!(stack_b = (t_stack_b *)malloc(sizeof(t_stack_b))))
            return 0;
        stack_a = NULL;
        stack_b = NULL;
        ft_parse(&stack_a, argv);
        if (ft_is_sorted(stack_a) && !ft_duplicate(stack_a))
        {
            cml = NULL;
            while (1)
            {
                cml = get_next_line(0);
                  if(!cml)
                    break;
                ft_comapare_command(cml, &stack_a, &stack_b);
                free(cml);
            }
            ft_print(&stack_a, &stack_b);
        }
        else
            ft_error();
    }
}