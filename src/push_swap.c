/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/10 17:51:22 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_simple(t_node *a, char *message)
{
	t_node	*current;

	current = a;

	printf("%s", message);
	while (current != NULL)
	{
		printf("Node nb = %i\n", current->nb);
		current = current->next;
	}
}

void	print_full(t_node *a, char *message)
{
	t_node	*current;

	current = a;

	printf("%s", message);
	while (current != NULL)
	{
		printf("Node adress = %p\n", current);
		printf("Node nb = %i\n", current->nb);
		printf("Node next = %p\n\n", current->next);
		current = current->next;
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
		print_simple(a, "Stack A Pre-Algo\n");
		// print_full(a, "Stack A Pre-Algo\n");
		master_algo(&a, &b);
		print_simple(a, "\nStack A Post-Algo\n");
		print_simple(b, "\nStack B Post-Algo\n");
		// print_full(a, "Stack A Post-Algo\n");
		free_stack(a);
		if (b != NULL)
			free_stack(b);
	}
	else
		printf("Error\n");
}

