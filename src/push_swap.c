/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/01/06 12:12:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_node **a)
{
	t_node *current;

	current = *a;
	while (current->next != NULL)
	{
		printf("Current node = %i\n", current->nb);
		current++;
	}
}

int	main(int ac, char **av)
{
	
}
