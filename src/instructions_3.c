/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:27 by flverge           #+#    #+#             */
/*   Updated: 2024/01/11 14:41:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_node **a, bool to_print)
{
	t_node	*old_last;
	t_node	*new_last;

	if (lstsize(*a) < 2)
		return ;
	old_last = *a;
	new_last = *a;
	while (old_last->next != NULL)
		old_last = old_last->next;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	lstadd_front(a, lstnew(old_last->nb));
	new_last->next = NULL;
	free(old_last);
	if (to_print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, bool to_print)
{
	t_node	*old_last;
	t_node	*new_last;

	if (lstsize(*b) < 2)
		return ;
	old_last = *b;
	new_last = *b;
	while (old_last->next != NULL)
		old_last = old_last->next;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	lstadd_front(b, lstnew(old_last->nb));
	new_last->next = NULL;
	free(old_last);
	if (to_print)
		ft_printf("rra\n");
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