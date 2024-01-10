/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:21 by flverge           #+#    #+#             */
/*   Updated: 2024/01/10 17:07:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_node *a)
{
	int	temp;

	if (lstsize(a) < 2)
	{
		printf("stack b too small");
		return ;
	}
	// ! swap function
	temp = a->nb;
	a->nb = a->next->nb;
	a->next->nb = temp;
	ft_printf("sa\n");
}

void	swap_b(t_node *b)
{
	int	temp;

	if (lstsize(b) < 2)
	{
		printf("stack b too small");
		return ;
	}
	// ! swap function
	temp = b->nb;
	b->nb = b->next->nb;
	b->next->nb = temp;
	ft_printf("sb\n");
}

/*

! sa (swap a): 
Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

! sb (swap b): 
Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

! ss :
sa and sb at the same time.

! pa (push a):
Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

! pb (push b):
Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

*/