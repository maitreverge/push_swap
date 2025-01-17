/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:24 by flverge           #+#    #+#             */
/*   Updated: 2025/01/13 20:43:21 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_node **a, bool to_print)
{
	t_node	*old_head;

	old_head = *a;
	if (lstsize(*a) < 2)
		return ;
	else if (lstsize(*a) == 2)
		sa(a, false);
	else
	{
		lstadd_back(a, old_head);
		(*a) = (*a)->next;
		old_head->next->prev = NULL;
		old_head->next = NULL;
	}
	if (to_print)
		ft_printf("ra\n");
}

void	rb(t_node **b, bool to_print)
{
	t_node	*old_head;

	old_head = *b;
	if (lstsize(*b) < 2)
		return ;
	else if (lstsize(*b) == 2)
		sb(b, false);
	else
	{
		lstadd_back(b, old_head);
		(*b) = (*b)->next;
		old_head->next->prev = NULL;
		old_head->next = NULL;
	}
	if (to_print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	ra(a, false);
	rb(b, false);
	ft_printf("rr\n");
}
