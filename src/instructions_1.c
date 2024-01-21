/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:21 by flverge           #+#    #+#             */
/*   Updated: 2024/01/21 10:31:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node **a, bool to_print)
{
	t_node	*current;
	int		temp_nb;
	int		temp_index;

	current = *a;
	if (lstsize(current) < 2)
		return ;
	temp_nb = current->nb;
	temp_index = current->master_index;
	current->nb = current->next->nb;
	current->master_index = current->next->master_index;
	current->next->nb = temp_nb;
	current->next->master_index = temp_index;
	if (to_print)
		ft_printf("sa\n");
}

void	sb(t_node **b, bool to_print)
{
	t_node	*current;
	int		temp_nb;
	int		temp_index;

	current = *b;
	if (lstsize(current) < 2)
		return ;
	temp_nb = current->nb;
	temp_index = current->master_index;
	current->nb = current->next->nb;
	current->master_index = current->next->master_index;
	current->next->nb = temp_nb;
	current->next->master_index = temp_index;
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
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = *a;
	stack_b = *b;
	if (!lstsize(stack_a))
		return ;
	else if (!stack_b)
		stack_b = lstnew(stack_a->nb, stack_a->master_index);
	else
		lstadd_front(b, lstnew(stack_a->nb, stack_a->master_index));
	free_node(a);
	if (to_print)
		ft_printf("pb\n");
}

void	ss(t_node **a, t_node **b)
{
	sa(a, false);
	sb(b, false);
	ft_printf("ss\n");
}
