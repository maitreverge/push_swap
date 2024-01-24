/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 18:27:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	little_algos(t_node **a, t_node **b, int size)
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
