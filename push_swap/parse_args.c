/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:30:50 by pamone            #+#    #+#             */
/*   Updated: 2023/12/01 14:30:50 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_end(t_stack *head)
{
	t_stack	*node;

	node = NULL;
	if (head == NULL)
		return (NULL);
	node = head;
	while (node->link)
	{
		node = node->link;
		if (node->link == NULL)
			return (node);
	}
	return (node);
}

void	ft_stack_append(t_stack **stack, int data)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->index = -1;
	new_node->link = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = ft_stack_end(*stack);
		last_node->link = new_node;
	}
}

void	free_str_array(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_parse(t_stack **stack_a, char *args[])
{
	int		i;
	char	*nor;
	char	**str;

	i = -1;
	nor = ft_strjoin(args);
	str = ft_split(nor, ' ');
	while (str[++i] != NULL )
	{
		if (ft_check_ascii(str[i]) || ft_check_overflow(ft_atoi(str[i])))
		{
			ft_error();
			free(nor);
			free_str_array(str);
			ft_free_stack(*stack_a);
			exit(EXIT_FAILURE);
		}
		else
			ft_stack_append(stack_a, ft_atoi(str[i]));
	}
	free(nor);
	free_str_array(str);
	ft_assign_index(stack_a);
}
