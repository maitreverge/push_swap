/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_master_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:24:11 by flverge           #+#    #+#             */
/*   Updated: 2024/01/25 09:58:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *buffer, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (buffer[j] > buffer[j + 1])
			{
				temp = buffer[j];
				buffer[j] = buffer[j + 1];
				buffer[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	allocate_index(t_node **a, int *buffer, int len_a)
{
	t_node	*head;
	int		index;

	head = *a;
	index = 0;
	while (index < len_a)
	{
		if (head->nb == buffer[index])
		{
			head->master_index = index;
			index++;
		}
		head = head->next;
		if (!head)
			head = *a;
	}
}

bool	no_num_left(t_node **a, int num, int low)
{
	t_node	*current;

	current = *a;
	if (low)
	{
		while (current)
		{
			if (current->master_index < (size_t)num)
				return (false);
			current = current->next;
		}
	}
	else
	{
		while (current)
		{
			if (current->master_index > (size_t)num)
				return (false);
			current = current->next;
		}
	}
	return (true);
}

bool	calculate_low(t_node **b, int max)
{
	t_node	*current;
	int		size;
	int		i;

	current = *b;
	size = lstsize(current);
	i = 0;
	while (i < size / 2)
	{
		if (current->master_index == (size_t)max)
			return (true);
		i++;
		current = current->next;
	}
	return (false);
}
