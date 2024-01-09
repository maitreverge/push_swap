/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/09 11:12:41 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_node *a)
{
	t_node *current;

	current = a;

	while (current->next != NULL)
	{
		printf("Node = %i\n", current->nb);
		current = current->next;
	}

	
}

int	main(int ac, char **av)
{
	t_node *a;
	// t_node b;

	a = NULL;
	// b = NULL;
	// basic check for forbidden chars
	if (!check_arg(ac, av))
	{
		init_stack(ac, av, &a);
		print_stack(a);
		free_stack(a);
	}
	else
		printf("Error\n");
}

