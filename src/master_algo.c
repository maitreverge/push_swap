/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:28 by flverge           #+#    #+#             */
/*   Updated: 2024/01/15 20:37:56 by flverge          ###   ########.fr       */
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
    
    while (current_a != NULL)
        current_a->radix = current_a->nb % i;
        current_a = current_a->next;
    }
    while (current_b != NULL)
    {
        current_b->radix = current_b->nb % i;
        current_b = current_b->next;
    }
}

bool    no_j_left(t_node **node, int j)
{
    t_node *current;

    current = *node;

    while (current)
    {
        if (current->radix == j)
            return false;
        current = current->next;
    }
    return true;
}

void    master_algo(t_node **a, t_node **b)
{
    t_node *current_a;
    t_node *current_b;
    
    current_a = *a;
    current_b = *b;
    if (lstsize(*a) < 2)
        return ;
    if (not_already_sorted(a)) // turn this maybe into a while outter loop
    {
        int i = 10; // calculate i based on the maximum number in stack a
        int j = 0;
        while (a && j < i) // loop until j is equal to i
        {
            calculate_radix(a, b, i);
            while (!no_j_left(a, j))
            {
                if ((*a)->radix == j)
                    pb(a, b, true);
                else
                    ra(a, true);
            }
            j++;
        }
    }
    else // already sorted a first time
    {
        printf("\nALREADY SORTED\n");
        return ; // ! needs freeing ?
    }
}


