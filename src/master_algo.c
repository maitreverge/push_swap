/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:28 by flverge           #+#    #+#             */
/*   Updated: 2024/01/11 15:23:47 by flverge          ###   ########.fr       */
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
    result = current->nb;
    while (current != NULL)
    {
        // printf("Current nb = %i\n", current->nb);
        if (current->nb > result)
            result = current->nb;
        current = current->next;
    }
    return result / 10;
}

void    master_algo(t_node **a, t_node **b)
{
    t_node *current_a;
    t_node *current_b;

 
    int max_radix = find_max(a);
    printf("Max = %i", max_radix);
    
    current_a = *a;
    current_b = *b;
	if (lstsize(*a) < 2)
		return ;
    if (not_already_sorted(a))
    {
        while (max_radix != 0) // outter loop for knowing the max number
        {

            // last condition
            max_radix = max_radix / 10;           
        }
    }
    else // already sorted a first time
        return ; // ! needs freeing ?
}
