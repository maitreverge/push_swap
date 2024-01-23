/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:25:59 by flverge           #+#    #+#             */
/*   Updated: 2024/01/23 09:56:05 by flverge          ###   ########.fr       */
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

// t_node *calculate_lcs(t_node **a)
// {
// 	t_node *current;
// 	t_node *result;

// 	current = *a;
// 	result = *a;

// 	while (current)
// 	{
// 		if 
// 	}
// 	return (result);
// }

size_t cost_first_node(t_node **a, t_node **b)
{
	t_node *head_a;
	t_node *head_b;
	size_t result_rb;
	size_t result_rrb;

	head_a = *a;
	head_b = *b;
	result_rb = 0;
	result_rrb = 0;
	if (head_a->master_index > head_b->master_index)
		return (0);
	else
	{
		while (head_a->master_index < head_b->master_index)
		{
			rb(head_b, false);
			result_rb++;
		}
		head_a = *a;
		head_b = *b;
		while (head_a->master_index < head_b->master_index)
		{
			rrb(head_b, false);
			result_rrb++;
		}
	}
	
	// pb(head_a, head_b, false);
	if (result_rb < result_rrb)
		return 1; // 1 == rb
	return 2; // 2 = rrb
	// return (result);
	
}

void	master_algo(t_node **a, t_node **b)
{
	t_node *lcs;
	size_t cost_node;
	// ! STEP 1 : calculate the indexes
	master_index(a, 0);
	// ! optionnal STEP 1 : calculate the longest consecutive sequence
	// lcs = calculate_lcs(a);

	while (*a)
	{
		if (!(*b))
			pb(a, b, true);
		cost_node = cost_first_node(a, b);
		if (!cost_node)
			pb(a, b, true);
		else if (cost_node == 1) // rb
		{
			
		}
			
		
	}
		// pb(a, b, true);
	
	
	// ! STEP 3 : 
	
	// ! STEP 

	

	
}

// ! Calculer le cout total du premier element, et regarder a cout + 1 MAX au debut et a la fin