/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:28 by flverge           #+#    #+#             */
/*   Updated: 2024/01/11 10:46:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     already_sorted(t_node **a)
{
    t_node *current;
    t_node *next;

    current = *a;
    next = current->next;
    while (next->next != NULL)
    {
        if (current->nb > next->nb)
            return (1);
        current = current->next;
        next = current->next;
    }
    return (0);
}

void    master_algo(t_node **a, t_node **b)
{
    int len_a;
    int len_b;

    len_a = lstsize(*a);
    len_b = lstsize(*b);
	// printf("size of a = %i\n", len_a);
	// printf("size of b = %i\n", len_b);
	if (len_a < 2)
		return ;
    if (already_sorted(a))
    {
        // ? Implement a single algorithm or several
        // sa(a);
        // sb(*b); // ! need further testing
		pb(a, b); // ! needs testing
		pb(a, b); // ! needs testing
		// sa(a);
		sb(b);
		pa(a, b); // ! needs testing
		// pa(a, b); // ! needs testing
		// ss(a, b);
		// sa(a);

    }
    else
    {
        printf("Shit's already sorted\n");
        return ; // ! needs freeing ?
    }
    
}
