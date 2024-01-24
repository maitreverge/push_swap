/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 08:50:59 by flverge          ###   ########.fr       */
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

void	sort_3(t_node **a)
{
	t_node *current;
	int nb1;
	int nb2;
	int nb3;

	current = *a;
	nb1 = current->nb;
	nb2 = current->next->nb;
	nb3 = current->next->next->nb;
	if (nb1 < nb3 && nb3 < nb2) // 1 3 2 sa ra
	{
		sa(a, true);
		ra(a, true);
	}
	else if (nb2 < nb1 && nb1 < nb3) // 2 1 3 sa
		sa(a, true);
	else if (nb2 < nb3 && nb3 < nb1) // 2 3 1 rra
		rra(a, true);
	else if (nb3 < nb1 && nb1 < nb2) // 3 1 2 ra
		ra(a, true);
	else if (nb3 < nb2 && nb2 < nb1) // 3 2 1 sa rra
	{
		sa(a, true);
		rra(a, true);
	}
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
		init_stack(ac, av, &a);
		size = lstsize(a);
		if (size < 10)
			little_algos(&a, &b, size);
		else if (size < 150)
			master_algo(&a, &b, 3);
		else
			master_algo(&a, &b, 20);
		// print_simple(a, "\nStack A Pre-Algo\n");
		// print_simple(b, "\nStack B Pre-Algo\n");
		print_full(a, "Stack A Pre-Algo\n");
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

