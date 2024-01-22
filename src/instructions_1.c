/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:21 by flverge           #+#    #+#             */
/*   Updated: 2024/01/22 10:46:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node **a, bool to_print)
{
	t_node	*head;
	t_node	*second_node;
	int		temp_nb;
	int		temp_index;

	if (lstsize(*a) < 2)
		return ;
	head = *a;
	second_node = head->next;
	temp_nb = head->nb;
	head->nb = second_node->nb;
	second_node->nb = temp_nb;
	temp_index = head->master_index;
	head->master_index = second_node->master_index;
	second_node->master_index = temp_index;
	if (to_print)
		ft_printf("sa\n");
}

void	sb(t_node **b, bool to_print)
{
	t_node	*head;
	t_node	*second_node;
	int		temp_nb;
	int		temp_index;

	if (lstsize(*b) < 2)
		return ;
	head = *b;
	second_node = head->next;
	temp_nb = head->nb;
	head->nb = second_node->nb;
	second_node->nb = temp_nb;
	temp_index = head->master_index;
	head->master_index = second_node->master_index;
	second_node->master_index = temp_index;
	if (to_print)
		ft_printf("sb\n");
}

void	pa(t_node **a, t_node **b, bool to_print)
{
	if (to_print)
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b, bool to_print)
{
	if (to_print)
		ft_printf("pb\n");
}

void	ss(t_node **a, t_node **b)
{
	sa(a, false);
	sb(b, false);
	ft_printf("ss\n");
}
