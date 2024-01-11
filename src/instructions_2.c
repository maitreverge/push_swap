/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:24 by flverge           #+#    #+#             */
/*   Updated: 2024/01/11 11:49:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ! function needs to be valgrinded
void	ra(t_node **a, bool to_print)
{
	t_node *new_first;
	t_node *new_last;
	t_node *old_first;

	if (lstsize(*a) < 2)
		return ;
	new_last = *a;
	old_first = *a;
	new_first = (*a)->next;
	
	lstadd_back(a, lstnew(old_first->nb));
	*a = new_first;
	free(old_first);
	if (to_print)
		ft_printf("ra\n");
}

// ! function needs to be valgrinded
void	rb(t_node **b, bool to_print)
{
	t_node *new_first;
	t_node *new_last;
	t_node *old_first;
	
	if (lstsize(*b) < 2)
		return ;
	new_last = *b;
	old_first = *b;
	new_first = (*b)->next;
	
	lstadd_back(b, lstnew(old_first->nb));
	*b = new_first;
	free(old_first);
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