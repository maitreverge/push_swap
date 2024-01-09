/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:28 by flverge           #+#    #+#             */
/*   Updated: 2024/01/09 14:33:10 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     already_sorted(t_node **a)
{
    t_node *current;
    t_node *next;

    current = *a;
    next = current->next;
    while (current->next != NULL)
    {
        if (current->nb > next->nb)
            return (1);
        current = next;
        next = current->next;
    }
    return (0);
}

void    master_algo(t_node **a, t_node **b)
{
    int len_stack;

    len_stack = lstsize(*a);
    // printf("Len stack = %i\n", len_stack);
    // ! Check if stack is already sorted
    if (!already_sorted(a))
        printf("Shit's already sorted\n");
    
}
