/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:27 by flverge           #+#    #+#             */
/*   Updated: 2024/01/20 09:44:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_node **a, bool to_print)
{
    if (to_print)
        ft_printf("rra\n");
}

void	rrb(t_node **b, bool to_print)
{
    if (to_print)
        ft_printf("rrb\n");
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