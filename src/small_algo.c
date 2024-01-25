/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:08:02 by flverge           #+#    #+#             */
/*   Updated: 2024/01/25 16:16:36 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	test_ra(t_node **a, int min)
{
	t_node	*current;
	int		result;

	current = (*a)->next;
	result = 1;
	while (current)
	{
		if (current->nb == min)
			break ;
		result++;
		current = current->next;
	}
	return (result);
}

static int	test_rra(t_node **a, int min)
{
	t_node	*current;
	int		result;

	current = lstlast(*a);
	result = 1;
	while (current)
	{
		if (current->nb == min)
			break ;
		result++;
		current = current->prev;
	}
	return (result);
}

static bool	sub_selection(t_node **a, t_node **b, int *size, int *min)
{
	*size = lstsize(*a);
	if (*size == 3)
	{
		sort_3(a);
		return (true);
	}
	*min = find_min(a);
	if ((*a)->nb == *min)
	{
		pb(a, b, true);
		(*size)--;
	}
	return (false);
}

void	selection_sort(t_node **a, t_node **b)
{
	int	min;
	int	size;
	int	var_ra;
	int	var_rra;

	while (*a)
	{
		if (sub_selection(a, b, &size, &min))
			break ;
		else
		{
			var_ra = test_ra(a, min);
			var_rra = test_rra(a, min);
			if (var_ra <= var_rra)
				ra(a, true);
			else
				rra(a, true);
		}
	}
	while (*b)
		pa(a, b, true);
}

void	sort_3(t_node **a)
{
	t_node	*current;
	int		min;
	int		middle;
	int		max;

	current = *a;
	min = find_min(a);
	max = find_max(a);
	middle = find_middle(a, min, max);
	if (min == current->nb && max == current->next->nb)
	{
		sa(a, true);
		ra(a, true);
	}
	else if (middle == current->nb && min == current->next->nb)
		sa(a, true);
	else if (middle == current->nb && max == current->next->nb)
		rra(a, true);
	else if (max == current->nb && min == current->next->nb)
		ra(a, true);
	else if (max == current->nb && middle == current->next->nb)
	{
		sa(a, true);
		rra(a, true);
	}
}
