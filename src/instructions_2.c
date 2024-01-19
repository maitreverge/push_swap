/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:24 by flverge           #+#    #+#             */
/*   Updated: 2024/01/19 12:35:35 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ! function needs to be valgrinded
void	ra(t_node **a, bool to_print)
{
    if (to_print)
        ft_printf("ra\n");
}

void	rb(t_node **b, bool to_print)
{
    if (to_print)
        ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	ra(a, false);
	rb(b, false);
	ft_printf("rr\n");
}
/*

! ra (rotate a): 
Shift up all elements of stack a by 1. The first element becomes the last one.

!rb (rotate b):
Shift up all elements of stack b by 1. The first element becomes the last one.

!rr :
ra and rb at the same time.

*/