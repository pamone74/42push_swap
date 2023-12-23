/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:58:57 by pamone            #+#    #+#             */
/*   Updated: 2023/11/30 18:58:57 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_len(const char *str, int c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_count_substring(const char *str, int c)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && !flag)
		{
			count++;
			flag = 1;
		}
		else if (*str == c && flag)
			flag = 0;
		str ++;
	}
	return (count);
}

void	ft_free_split(char **str)
{
	char	**ptr;

	if (str == NULL)
		return ;
	ptr = str;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(str);
}

char	*ft_substr(const char *str, int start, int len)
{
	char			*copy;
	int				length_string;
	char			*store;
	int				i;

	copy = (char *)str;
	length_string = ft_strlen(copy);
	if (copy == NULL || start > length_string)
		return (NULL);
	if (len > length_string)
		len = length_string - start;
	store = malloc(sizeof(char) * len + 1);
	if (!store)
		return (NULL);
	i = 0;
	while (str[start] && i < len)
	{
		store[i] = str[start];
		start ++;
		i++;
	}
	store[i] = '\0';
	return (store);
}

char	**ft_split(const char	*str, int c)
{
	int		total_substring;
	int		i;
	char	**store;

	total_substring = ft_count_substring(str, c);
	store = malloc(sizeof(char *) * (total_substring + 1));
	if (! store)
		return (NULL);
	i = 0;
	while (i < total_substring)
	{
		while (*str == c)
			str++;
		store[i] = ft_substr(str, 0, ft_count_len(str, c));
		if (!store[i])
		{
			ft_free_split(store);
			return (NULL);
		}
		str += ft_count_len(str, c);
		i++;
	}
	store[i] = NULL;
	return (store);
}
