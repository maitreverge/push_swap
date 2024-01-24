/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:57:24 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 18:27:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node *to_free)
{
	t_node	*current;

	current = to_free;
	if (!current)
		return ;
	else if (!current->next)
	{
		free(current);
		return ;
	}
	while (current)
	{
		if (!current->next)
		{
			free(current);
			return ;
		}
		current = current->next;
		free(current->prev);
	}
}

int	find_min(t_node **a)
{
	t_node	*current;
	int		result;

	current = *a;
	result = INT_MAX;
	while (current)
	{
		if (current->nb <= result)
			result = current->nb;
		current = current->next;
	}
	return (result);
}

int	find_max(t_node **a)
{
	t_node	*current;
	int		result;

	current = *a;
	result = INT_MIN;
	while (current)
	{
		if (current->nb >= result)
			result = current->nb;
		current = current->next;
	}
	return (result);
}

int	find_middle(t_node **a, int min, int max)
{
	t_node	*current;
	int		result;

	current = *a;
	result = 0;
	while (current)
	{
		if (current->nb != min && current->nb != max)
			result = current->nb;
		current = current->next;
	}
	return (result);
}

void	quit_check(t_node **a, char *str)
{
	free_stack(*a);
	if (str)
		ft_printf("%s", str);
	exit (-1);
}
