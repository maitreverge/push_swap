/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:27 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 16:05:12 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_node **a, bool to_print)
{
	t_node	*old_head;
	t_node	*old_tail;

	old_head = *a;
	old_tail = lstlast(*a);
	if (lstsize(*a) < 2)
		return ;
	else if (lstsize(*a) == 2)
		sa(a, false);
	else
	{
		lstadd_front(a, old_tail);
		(*a)->prev->next = NULL;
		(*a)->prev = NULL;
	}
	if (to_print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, bool to_print)
{
	t_node	*old_head;
	t_node	*old_tail;

	old_head = *b;
	old_tail = lstlast(*b);
	if (lstsize(*b) < 2)
		return ;
	else if (lstsize(*b) == 2)
		sb(b, false);
	else
	{
		lstadd_front(b, old_tail);
		(*b)->prev->next = NULL;
		(*b)->prev = NULL;
	}
	if (to_print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, false);
	rrb(b, false);
	ft_printf("rrr\n");
}
