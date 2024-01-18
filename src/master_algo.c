/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:28 by flverge           #+#    #+#             */
/*   Updated: 2024/01/18 09:23:16 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool     already_sorted(t_node **a)
{
    t_node *current;

	if (!*a)
		return false;

    current = *a;
    while (current->next != NULL)
    {
        if (current->nb > current->next->nb)
            return false;
        current = current->next;
    }
    return true;
}

bool     already_reversed_sorted(t_node **a)
{
    t_node *current;

	if (!*a)
		return false;

    current = *a; 
    while (current->next != NULL)
    {
        if (current->nb < current->next->nb)
            return false;
        current = current->next;
    }
    return true;
}

int find_max(t_node **a)
{
    t_node *current;
    int result;

    current = *a;
    result = INT_MIN;
    while (current != NULL)
    {
        // printf("Current nb = %i\n", current->nb);
        if (current->nb > result)
            result = current->nb;
        current = current->next;
    }
    return result / 10;
}

void    calculate_radix(t_node **node, int i)
{
    t_node  *current;

    current = *node;
    
    while (current)
    {
        current->radix = current->nb % i;
        current = current->next;
    }
}

bool    no_j_left(t_node **node, int j)
{
    t_node *current;

    current = *node;

    while (current)
    {
        if (current->radix == j)
            return false;
        current = current->next;
    }
    return true;
}

void	display_radix(t_node **a, t_node **b)
{
	t_node *current_a;
	t_node *current_b;

	current_a = *a;
	current_b = *b;

	while (current_a)
	{
		printf("Current rdx node A = %i\n", current_a->radix);
		current_a = current_a->next;
	}

	while (current_b)
	{
		printf("Current rdx node B = %i\n", current_b->radix);
		current_b = current_b->next;
	}
}

void	rotate_stack_a(t_node **a, int i)
{
	t_node *current;
	int index = 0;

	current = *a;

	int len_stack = lstsize(current) / 2;

	while (current->radix != i)
	{
		index++;
		current = current->next;
	}
	
	if (index <= len_stack)
		ra(a, true);
	else
		rra(a, true);
}

void	rotate_stack_b(t_node **b, int i)
{
	t_node *current;
	int index = 0;

	current = *b;

	int len_stack = lstsize(current) / 2;

	while (current->radix != i)
	{
		index++;
		current = current->next;
	}
	
	if (index <= len_stack)
		rb(b, true);
	else
		rrb(b, true);
}

void    master_algo(t_node **a, t_node **b)
{
    t_node *current_a;
    t_node *current_b;
    
    current_a = *a;
    current_b = *b;
    if (lstsize(*a) < 2)
        return ;
    if (!already_sorted(a)) // turn this maybe into a while outter loop
    {
        int i = 10; // calculate i based on the maximum number in stack a
        int j = 0;
		// calculate_radix(a, i);
		
		// ! needs a master condition for making the two stacks go back and forth until a is sorted
		while (!already_sorted(a)) // ! OUTTER LOOP
		{
			while (*a) // * loop for a
			{
				calculate_radix(a, i);
				while (!no_j_left(a, j))
				{
					if ((*a)->radix == j)
						pb(a, b, true);
					else
						rotate_stack_a(a, j);
						// ra(a, true); // ! needs opti here if the next number is lower OR higher in the stack
					calculate_radix(a, i); // radix value does not follow during instructions
				}
				j++;
			}
			
			// ! If b is reversed sorted, push a until it ends
            if (already_reversed_sorted(b) && *b)
			{
				while (*b)
					pa(a, b, true);
			}
			
			else
			{
				i *= 10;
				j = 0;
				while (*b) // * loop for b
				{
					calculate_radix(b, i); // radix value does not follow during instructions
					while (!no_j_left(b, j))
					{
						if ((*b)->radix == j)
						{
							pa(a, b, true);
							// ra(a, true); // ? ra for making shit in the right order, maybe find another way around
						}
						else
							rotate_stack_b(b, j);
							// rb(b, true); // ! needs opti here if the next number is lower OR higher in the stack
						calculate_radix(b, i); // radix value does not follow during instructions
					}
					j++;
				}
				i *= 10;
				j = 0;
			}
		}
	}
    else // already sorted a first time
    {
        printf("\nALREADY SORTED\n");
        return ; // ! needs freeing ?
    }
}

