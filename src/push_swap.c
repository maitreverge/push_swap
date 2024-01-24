/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 16:20:31 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (min == current->nb)
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

int	test_ra(t_node **a, int min)
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

int	test_rra(t_node **a, int min)
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

void	selection_sort(t_node **a, t_node **b)
{
	int	min;
	int	size;
	int	var_ra;
	int	var_rra;

	size = lstsize(*a);
	while (size > 1)
	{
		if (size == 3)
		{
			sort_3(a);
			break ;
		}
		min = find_min(a);
		if ((*a)->nb == min)
		{
			pb(a, b, true);
			size--;
		}
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

void	little_algos(t_node **a, t_node **b, int size)
{
	if (size == 2)
	{
		if ((*a)->nb > (*a)->next->nb)
			sa(a, true);
	}
	else if (size == 3)
		sort_3(a);
	else
		selection_sort(a, b);
}

void	quit_check(t_node **a, char *str)
{
	free_stack(*a);
	if (str)
		ft_printf("%s", str);
	exit (-1);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (!check_arg(ac, av))
	{
		init_stack(ac, av, &a);
		if (a_is_sorted(&a))
			quit_check(&a, 0);
		if (a_contains_double(&a))
			quit_check(&a, "Error\n");
		size = lstsize(a);
		if (size < 10)
			little_algos(&a, &b, size);
		else if (size < 150)
			master_algo(&a, &b, 10);
		else
			master_algo(&a, &b, 20);
		free_stack(a);
		free_stack(b);
	}
	else
		printf("Error\n");
}

