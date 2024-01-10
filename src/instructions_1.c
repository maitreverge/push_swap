/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:18:21 by flverge           #+#    #+#             */
/*   Updated: 2024/01/10 17:56:21 by flverge          ###   ########.fr       */
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
		printf("stack b too small");
		return ;
	}
	// ! swap function
	temp = *a->nb;
	*a->nb = *a->next->nb;
	*a->next->nb = temp;
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
	// ! swap function
	temp = *b->nb;
	*b->nb = *b->next->nb;
	*b->next->nb = temp;
	ft_printf("sb\n");
}

/**
 * @brief Take the first element at the top
 * of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * @param a 
 * @param b 
 */
void	pb(t_node *a, t_node *b)
{
	// t_node *first_a;
	t_node *next_a;

	// first_a = a;
	next_a = a->next;

	// ! security if a is empty
	if (!a)
		return ;
	if (b == NULL)
	{
		b = lstnew(a->nb);
	}
	else
	{
		lstadd_front(&b, lstnew(a->nb));
	}
	a = next_a;


	ft_printf("pb\n");
	// print_simple(b, "\nStack B Post-Algo\n");

	/*
	while (i < size)
	{
		if (*a == NULL)
			*a = lstnew((int)buffer[i]);
		else
			lstadd_back(a, lstnew((int)buffer[i]));
		i++;
	}
	
	*/
	// at the end, move pointer
	
}

/*

! sa (swap a): 
Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

! sb (swap b): 
Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

! ss :
sa and sb at the same time.

! pa (push a):
Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

! pb (push b):
Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

*/