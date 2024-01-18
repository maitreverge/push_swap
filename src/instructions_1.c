/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:21 by flverge           #+#    #+#             */
/*   Updated: 2024/01/18 14:00:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node **a, bool to_print)
{
	int	temp_nb;
	int	temp_index;

	if (lstsize(*a) < 2)
		return ;
	temp_nb = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = temp_nb;

	temp_index = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp_index;
	if (to_print)
		ft_printf("sa\n");
}

void	sb(t_node **b, bool to_print)
{
	int	temp_nb;
	int	temp_index;

	if (lstsize(*b) < 2)
		return ;
	temp_nb = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = temp_nb;

	temp_index = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp_index;
	if (to_print)
		ft_printf("sb\n");
}

void	pa(t_node **a, t_node **b, bool to_print)
{
    t_node	*current_b;

    if (!*b)
        return ;
    current_b = *b;
    *b = (*b)->next;
    if (*b != NULL)
        (*b)->prev = NULL;
    lstadd_front(a, current_b);
    if (to_print)
        ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b, bool to_print)
{
    t_node	*current_a;

    if (!*a)
        return ;
    current_a = *a;
    *a = (*a)->next;
    if (*a != NULL)
        (*a)->prev = NULL;
    lstadd_front(b, current_a);
    if (to_print)
        ft_printf("pb\n");
}

void	ss(t_node **a, t_node **b)
{
	sa(a, false);
	sb(b, false);
	ft_printf("ss\n");
}
