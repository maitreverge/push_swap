/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:25:59 by flverge           #+#    #+#             */
/*   Updated: 2024/01/23 15:04:58 by flverge          ###   ########.fr       */
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

// size_t cost_first_node(t_node **a, t_node **b)
// {
// 	t_node *head_a;
// 	t_node *head_b;
// 	t_node *tail_a;
// 	t_node *tail_b;
// 	size_t result_rb;
// 	size_t result_rrb;

// 	head_a = *a;
// 	head_b = *b;
	
// 	tail_a = lstlast(*a);
// 	tail_b = lstlast(*b);
	
// 	result_rb = 0;
// 	result_rrb = 0;
	
// 	if ((head_a->master_index > head_b->master_index)
// 		&& (head_b->master_index > tail_b->master_index)) // biggest number at the top of stack b
// 		return (0);
// 	else // needs to make rra
// 	{
// 		while ((head_a->master_index < head_b->master_index)
// 			&& (head_b->master_index < tail_b->master_index))
// 		{
// 			rb(head_b, false);
// 			head_a = *a;
// 			head_b = *b;
// 			tail_a = lstlast(*a);
// 			tail_b = lstlast(*b);
// 			result_rb++;
// 		}
// 		head_a = *a;
// 		head_b = *b;
// 		while ((head_a->master_index < head_b->master_index)
// 			&& (head_b->master_index < tail_b->master_index))
// 		{
// 			rrb(head_b, false);
// 			head_a = *a;
// 			head_b = *b;
// 			tail_a = lstlast(*a);
// 			tail_b = lstlast(*b);
// 			result_rrb++;
// 		}
// 	}
	
// 	// pb(head_a, head_b, false);
// 	if (result_rb < result_rrb)
// 		return result_rb; // 1 == rb
// 	return result_rrb; // 2 = rrb
// 	// return (result);
	
// }

bool	no_num_left(t_node **a, int num, int low)
{
	t_node *current;

	current = *a;
	if (low)
	{
		while (current)
		{
			if (current->master_index < num)
				return false;
			current = current->next;
		}
		// return true;
	}
	else
	{
		while (current)
		{
			if (current->master_index > num)
				return false;
			current = current->next;
		}
	}
	return true;
}

void	master_algo(t_node **a, t_node **b)
{
	// ! STEP 1 : calculate the indexes
	master_index(a, 0);
	// ! optionnal STEP 1 : calculate the longest consecutive sequence
	// lcs = calculate_lcs(a);

	int max = lstsize(*a) - 1;
	
	int divider = 2;
	
	int num_lower = max / divider;
	int num_upper = max / divider;
	
	while (*a)
	{
		if ((*a)->master_index >= num_upper)
		{
			pb(a, b, true);
		}
		else if ((*a)->master_index < num_lower)
		{
			pb(a, b, true);
			rb(b, true);
		}
		// else
		ra(a, true); //no need optimisation on the first run
		// if (no_num_left(a, num_lower, 1))
		// 	num_lower /= 2;
		// if (no_num_left(a, num_upper, 0))
		// 	num_upper *= 0.5;
	}
	num_lower /= 2;
	num_upper += num_lower;
	while (*b)
	{
		if ((*b)->master_index > num_upper)
		{
			pa(a, b, true);
		}
		else if ((*b)->master_index < num_lower)
		{
			pa(a, b, true);
			ra(a, true);
		}
		else
		{
			rb(b, true);
			printf("num lower = %i\n", num_lower);
			printf("num upper = %i\n", num_upper);
		}
		if (no_num_left(b, num_lower, 1))
			num_lower /= 2;
		else if (no_num_left(b, num_upper, 0))
			num_upper += num_lower;
		// 	num_upper *= 1.5;
	}
		// pb(a, b, true);
	
	
	// ! STEP 3 : 
	
	// ! STEP 

	

	
}

// ! Calculer le cout total du premier element, et regarder a cout + 1 MAX au debut et a la fin