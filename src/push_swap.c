/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 13:14:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_simple(t_node *a, char *message)
{
	t_node *head;

	head = a;
	printf("\033[32;1m%s\033[0m\n", message);
	if (!a)
		return ;
	do
	{
		printf("Node nb = %i\n", head->nb);
		head = head->next;
	} while (head);
}

void	print_full(t_node *a, char *message)
{
	t_node *head;

	head = a;
	printf("\033[32;1m%s\033[0m\n", message);
	if (!a)
		return ;
	do
	{
		printf("Node adress = %p\n", head);
		printf("Node nb = %i\n", head->nb);
		printf("Node index = %zu\n", head->master_index);
		if (!head->prev)
			printf("\033[1;31mNode prev = %p\n\033[0m", head->prev); // red
		else
			printf("Node prev = %p\n", head->prev); // green
		if (!head->next)
			printf("\033[1;31mNode next = %p\n\n\033[0m", head->next);
		else
			printf("Node next = %p\n\n", head->next);
		head = head->next;
	} while (head);
}

int	find_min(t_node **a)
{
	int result;

	result = INT_MAX;
	t_node *current;

	current = *a;
	while (current)
	{
		if (current->nb <= result)
			result = current->nb;
		current = current->next;
	}
	return result;
}

int	find_max(t_node **a)
{
	int result;

	result = INT_MIN;
	t_node *current;

	current = *a;
	while (current)
	{
		if (current->nb >= result)
			result = current->nb;
		current = current->next;
	}
	return result;
}

int find_middle(t_node **a, int min, int max)
{
	int result;

	result = 0;
	t_node *current;

	current = *a;
	while (current)
	{
		if (current->nb != min && current->nb != max)
			result = current->nb;
		current = current->next;
	}
	return result;
}

void	sort_3(t_node **a)
{
	t_node *current;
	int min;
	int middle;
	int max;

	current = *a;
	min = find_min(a);
	max = find_max(a);
	middle = find_middle(a, min, max);
	if (min == current->nb) // 1 3 2 sa ra
	{
		sa(a, true);
		ra(a, true);
	}
	else if (middle == current->nb && min == current->next->nb) // 2 1 3 sa
		sa(a, true);
	else if (middle == current->nb && max == current->next->nb) // 2 3 1 rra
		rra(a, true);
	else if (max == current->nb && min == current->next->nb) // 3 1 2 ra
		ra(a, true);
	else if (max == current->nb && middle == current->next->nb) // 3 2 1 sa rra
	{
		sa(a, true);
		rra(a, true);
	}
}

int	test_ra(t_node **a, int min)
{
	t_node *current;
	int result = 1;

	current = (*a)->next;
	while (current)
	{
		if (current->nb == min)
			break ;
		result++;
		current = current->next;
	}
	// Return the smaller of i and (size - i)
	return (result);
}

int	test_rra(t_node **a, int min)
{
	t_node *current;
	int result = 1;

	current = lstlast(*a);
	while (current)
	{
		if (current->nb == min)
			break ;
		result++;
		current = current->prev;
	}
	// Return the smaller of i and (size - i)
	return (result);
}

void	selection_sort(t_node **a, t_node **b)
{
	int min;
	int size;
	int var_ra;
	int var_rra;

	size = lstsize(*a);
	while (size > 1)  // Stop when there's only one element left in stack a
	{
		if (size == 3)
		{
			sort_3(a);
			break;
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
		if ((*a)->nb > (*a)->next->nb) // possiblement inutile
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
	t_node *a;
	t_node *b;
	int size;

	a = NULL;
	b = NULL;
	// basic check for forbidden chars
	if (!check_arg(ac, av))
	{
		// for(int i = 0; av[i]; i++)
		// 	printf("Current av = %s\n", av[i]);
		init_stack(ac, av, &a);
		if (a_is_sorted(&a))
			quit_check(&a, 0);
		if (a_contains_double(&a))
			quit_check(&a, "Error\n");
		// something wrong here 
		// print_simple(a, "\nStack A Pre-Algo\n");
		size = lstsize(a);
		// printf("Size = %i", size);
		if (size < 10)
			little_algos(&a, &b, size);
		else if (size < 150)
			master_algo(&a, &b, 10);
		else
			master_algo(&a, &b, 20);
		// print_simple(b, "\nStack B Pre-Algo\n");
		// print_full(a, "Stack A Pre-Algo\n");
		// printf("\nLenght node = %i\n", lstsize(a));
		// print_full(b, "Stack B Pre-Algo\n");
		// print_simple(a, "\nStack A Post-Algo\n");
		// print_simple(b, "\nStack B Post-Algo\n");
		// print_full(a, "\nStack A Post-Algo\n");
		// print_full(b, "\nStack B Post-Algo\n");
		free_stack(a); // ! self secured function
		free_stack(b); // ! self secured function
	}
	else
		printf("Error\n");
}

