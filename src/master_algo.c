/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:25:59 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 18:25:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_algo	init_struct_algo(t_node **a, int numerator)
{
	t_algo	new;

	new.max = lstsize(*a) - 1;
	new.soustraction = new.max / numerator;
	new.num_lower = new.soustraction;
	new.num_upper = new.max - new.soustraction;
	return (new);
}

static void	master_index(t_node **a, int i)
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

static void	sub_algo(t_node **a, t_node **b, t_algo *algo)
{
	while (*b)
	{
		if ((*b)->master_index == algo->max)
		{
			pa(a, b, true);
			algo->max--;
		}
		else
		{
			if (calculate_low(b, algo->max))
				rb(b, true);
			else
				rrb(b, true);
		}
	}
}

void	master_algo(t_node **a, t_node **b, int numerator)
{
	t_algo	algo;

	algo = init_struct_algo(a, numerator);
	master_index(a, 0);
	while (*a)
	{
		if ((*a)->master_index > algo.num_upper)
			pb(a, b, true);
		else if ((*a)->master_index <= algo.num_lower)
		{
			pb(a, b, true);
			rb(b, true);
		}
		else
			ra(a, true);
		if (no_num_left(a, algo.num_lower, 1))
			algo.num_lower += algo.soustraction;
		if (no_num_left(a, algo.num_upper, 0))
			algo.num_upper -= algo.soustraction;
	}
	sub_algo(a, b, &algo);
}
