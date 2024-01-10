/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:21 by flverge           #+#    #+#             */
/*   Updated: 2024/01/10 18:34:12 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * 
 * @param a 
 */
void	sa(t_node **a)
{
	int	temp;

	if (lstsize(*a) < 2)
	{
		printf("stack a too small");
		return ;
	}
	temp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = temp;
	ft_printf("sa\n");
}

/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 * 
 * @param b 
 */
void	sb(t_node **b)
{
	int	temp;

	if (lstsize(*b) < 2)
	{
		printf("stack b too small");
		return ;
	}
	temp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = temp;
	ft_printf("sb\n");
}

/**
 * @brief Take the first element at the top of b and
 * put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param a 
 * @param b 
 */
void	pa(t_node **a, t_node **b)
{
	t_node	*current_b;
	t_node	*next_b;

	current_b = *b;
	next_b = (*b)->next;
	if (!b)
		return ;
	if (*a == NULL)
		*a = lstnew((*b)->nb);
	else
		lstadd_front(a, lstnew((*b)->nb));
	*b = next_b;
	free(current_b);
	ft_printf("pa\n");
}

/**
 * @brief Take the first element at the top
 * of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * @param a 
 * @param b 
 */
void	pb(t_node **a, t_node **b)
{
	t_node	*current_a;
	t_node	*next_a;

	current_a = *a;
	next_a = (*a)->next;
	if (!a)
		return ;
	if (*b == NULL)
		*b = lstnew((*a)->nb);
	else
		lstadd_front(b, lstnew((*a)->nb));
	*a = next_a;
	free(current_a);
	ft_printf("pb\n");
}

/**
 * @brief sa and sb at the same time.
 * 
 * @param a 
 * @param b 
 */
void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}
