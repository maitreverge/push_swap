/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:28 by flverge           #+#    #+#             */
/*   Updated: 2024/01/15 08:18:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     not_already_sorted(t_node **a)
{
    t_node *current;
    t_node *next;

    current = *a;
    next = current->next;
    while (current->next != NULL)
    {
        if (current->nb > next->nb)
            return (1);
        current = current->next;
        next = current->next;
    }
    return (0);
}

int find_max(t_node **a)
{
    t_node *current;
    int result;

    current = *a;
    result = INT_MIN;
    while (current != NULL)
    {
        // printf("Current nb = %i\n", current->nb);
        if (current->nb > result)
            result = current->nb;
        current = current->next;
    }
    return result / 10;
}

void    calculate_radix(t_node **a, t_node **b, int i)
{
    t_node  *current_a;
    t_node  *current_b;

    current_a = *a;
    current_b = *b;
    
    while (current_a)
    {
        current_a->radix = current_a->nb % i;
        current_a = current_a->next;
    }
    while (current_b)
    {
        current_b->radix = current_b->nb % i;
        current_b = current_b->next;
    }
}

void    master_algo(t_node **a, t_node **b)
{
    // t_node *current_a;
    // t_node *current_b;

 
    // // int max_radix = find_max(a);
    // // printf("Max = %i\n", max_radix);
    
    // current_a = *a;
    // current_b = *b;
	// if (lstsize(*a) < 2)
	// 	return ;
    if (not_already_sorted(a)) // turn this maybe into a while outter loop
    {
        // int i = 10;
        // int j = 0;
        // calculate_radix(a, b, i);
        // while (a)
        // {
        //     if ((*a)->radix == j)
        //         pb(a, b, true);
        //     else
        //         ra(a, true);
        // }

		// ! testing leaks for instructions
		// pb(a, b, true);
		// pb(a, b, true);
		pb(a, b, true);
		pb(a, b, true);
		pb(a, b, true);
		pa(a, b, true);
		pa(a, b, true);
		pa(a, b, true);
		pa(a, b, true);
		// pb(a, b, true);
		// pb(a, b, true);

		
		// sb(b, true);
		// sb(b, true);
		// sb(b, true);
		// ss(a, b);
    }
    else // already sorted a first time
        return ; // ! needs freeing ?
}
