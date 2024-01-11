/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:24 by flverge           #+#    #+#             */
/*   Updated: 2024/01/11 11:22:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_node **a, bool to_print)
{
	if (to_print)
		ft_print("ra\n")
}

void	rb(t_node **a, bool to_print)
{
	if (to_print)
		ft_print("rb\n")
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