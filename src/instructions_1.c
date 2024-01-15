/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:21 by flverge           #+#    #+#             */
/*   Updated: 2024/01/15 08:20:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node **a, bool to_print)
{
	int	temp;

	if (lstsize(*a) < 2)
		return ;
	temp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = temp;
	if (to_print)
		ft_printf("sa\n");
}

void	sb(t_node **b, bool to_print)
{
	int	temp;

	if (lstsize(*b) < 2)
		return ;
	temp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = temp;
	if (to_print)
		ft_printf("sb\n");
}

void	pa(t_node **a, t_node **b, bool to_print)
{
	t_node	*current_b;
	t_node	*next_b;

	if (!*b)
		return ;
	current_b = *b;
	next_b = (*b)->next;
	if (*a == NULL)
		*a = lstnew((*b)->nb);
	else
		lstadd_front(a, lstnew((*b)->nb));
	*b = next_b;
	free(current_b);
	if (to_print)
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b, bool to_print)
{
	t_node	*current_a;
	t_node	*next_a;

	if (!*a)
		return ;
	current_a = *a;
	next_a = (*a)->next;
	if (*b == NULL)
		*b = lstnew((*a)->nb);
	else
		lstadd_front(b, lstnew((*a)->nb));
	*a = next_a;
	free(current_a);
	if (to_print)
		ft_printf("pb\n");
}

void	ss(t_node **a, t_node **b)
{
	sa(a, false);
	sb(b, false);
	ft_printf("ss\n");
}
