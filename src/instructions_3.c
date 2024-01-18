/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:27 by flverge           #+#    #+#             */
/*   Updated: 2024/01/18 14:01:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_node **a, bool to_print)
{
    t_node	*old_first;

    if (lstsize(*a) < 2)
        return ;
    old_first = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    old_first->next = NULL;
    old_first->prev = lstlast(*a);
    lstadd_back(a, old_first);
    if (to_print)
        ft_printf("ra\n");
}

void	rb(t_node **b, bool to_print)
{
    t_node	*old_first;

    if (lstsize(*b) < 2)
        return ;
    old_first = *b;
    *b = (*b)->next;
    (*b)->prev = NULL;
    old_first->next = NULL;
    old_first->prev = lstlast(*b);
    lstadd_back(b, old_first);
    if (to_print)
        ft_printf("rb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, false);
	rrb(b, false);
	ft_printf("rrr\n");
}

/*

!rra (reverse rotate a): 
Shift down all elements of stack a by 1. The last element becomes the first one.

!rrb (reverse rotate b):
Shift down all elements of stack b by 1. The last element becomes the first one.

!rrr :
rra and rrb at the same time.

*/