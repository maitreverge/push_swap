/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/21 10:36:39 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_simple(t_node *a, char *message)
{
	t_node *head;
	t_node *tail;

	head = a;
	tail = lstlast(a);

	printf("%s", message);
	if (!a)
		return ;
	else if (!head->next)
		printf("Node nb = %i\n", head->nb);
	else
	{
		do
		{
			printf("Node nb = %i\n", head->nb);
			head = head->next;
		} while (head != tail);
		printf("Node nb = %i\n", head->nb);
	}
}

void	print_full(t_node *a, char *message)
{
	t_node *head;
	t_node *tail;

	head = a;
	tail = lstlast(a);

	printf("%s", message);
	if (!a)
		return ;
	else if (!head->next)
	{
		printf("Node adress = %p\n", head);
		printf("Node nb = %i\n", head->nb);
		printf("Node index = %zu\n", head->master_index);
		printf("Node prev = %p\n", head->prev);
		printf("Node next = %p\n\n", head->next);
	}
	else
	{
		do
		{
			printf("Node adress = %p\n", head);
			printf("Node nb = %i\n", head->nb);
			printf("Node index = %zu\n", head->master_index);
			printf("Node prev = %p\n", head->prev);
			printf("Node next = %p\n\n", head->next);
			head = head->next;
		} while (head != tail);
		printf("Node adress = %p\n", head);
		printf("Node nb = %i\n", head->nb);
		printf("Node index = %zu\n", head->master_index);
		printf("Node prev = %p\n", head->prev);
		printf("Node next = %p\n\n", head->next);
	}
}

int	main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	// basic check for forbidden chars
	if (!check_arg(ac, av))
	{
		init_stack(ac, av, &a);
		// print_simple(a, "\nStack A Pre-Algo\n");
		// print_simple(b, "\nStack B Pre-Algo\n");
		print_full(a, "Stack A Pre-Algo\n");
		// printf("\nLenght node = %i\n", lstsize(a));
		print_full(b, "Stack B Pre-Algo\n");
		master_algo(&a, &b);
		// print_simple(a, "\nStack A Post-Algo\n");
		// print_simple(b, "\nStack B Post-Algo\n");
		print_full(a, "\nStack A Post-Algo\n");
		print_full(b, "\nStack B Post-Algo\n");
		if (a)
			free_stack(a); // ! self secured function
		if (b)
			free_stack(b); // ! self secured function
	}
	else
		printf("Error\n");
}

