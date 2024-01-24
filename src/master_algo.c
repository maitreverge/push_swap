/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:25:59 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 16:13:19 by flverge          ###   ########.fr       */
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

void	master_index(t_node **a, int i)
{
	t_node	*head;
	int		len_a;
	int		*buffer;

	head = *a;
	len_a = lstsize(*a);
	buffer = malloc(sizeof(int) * len_a);
	if (!buffer)
	{
		free_stack(*a);
		return ;
	}
	while (head)
	{
		buffer[i] = head->nb;
		i++;
		head = head->next;
	}
	bubble_sort(buffer, len_a);
	allocate_index(a, buffer, len_a);
	free(buffer);
}

bool	no_num_left(t_node **a, int num, int low)
{
	t_node	*current;

	current = *a;
	if (low)
	{
		while (current)
		{
			if (current->master_index < num)
				return (false);
			current = current->next;
		}
	}
	else
	{
		while (current)
		{
			if (current->master_index > num)
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
		if (current->master_index == max)
			return (true);
		i++;
		current = current->next;
	}
	return (false);
}

void	master_algo(t_node **a, t_node **b, int numerator)
{
	int	soustraction;
	int	num_lower;
	int	num_upper;
	int	max;

	soustraction = max / numerator;
	num_lower = soustraction;
	num_upper = max - soustraction;
	max = lstsize(*a) - 1;
	master_index(a, 0);
	while (*a)
	{
		if ((*a)->master_index > num_upper)
			pb(a, b, true);
		else if ((*a)->master_index <= num_lower)
		{
			pb(a, b, true);
			rb(b, true);
		}
		else
			ra(a, true);
		if (no_num_left(a, num_lower, 1))
			num_lower += soustraction;
		if (no_num_left(a, num_upper, 0))
			num_upper -= soustraction;
	}
	while (*b)
	{
		if ((*b)->master_index == max)
		{
			pa(a, b, true);
			max--;
		}
		else
		{
			if (calculate_low(b, max))
				rb(b, true);
			else
				rrb(b, true);
		}
	}
}
