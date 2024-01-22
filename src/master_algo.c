/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:25:59 by flverge           #+#    #+#             */
/*   Updated: 2024/01/22 19:17:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *buffer, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (buffer[j] > buffer[j + 1])
			{
				temp = buffer[j];
				buffer[j] = buffer[j + 1];
				buffer[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void master_index(t_node **a, int i)
{
	t_node *head;
	int len_a;
	int *buffer;

	head = *a;

	len_a = lstsize(*a);

	buffer = malloc(sizeof(int) * len_a);
	if (!buffer)
		exit; // secure the free with additionals free nodes

	// remplir le buffer avec les chiffres
	while (head)
	{
		buffer[i] = head->nb;
		i++;
		head = head->next;
	}

	bubble_sort(buffer, len_a);


	free(buffer);
}

void	master_algo(t_node **a, t_node **b)
{
	// ! STEP 1 : calculate the indexes
	master_index(a, 0);
	// ! STEP 1 : calculate the longest consecutive sequence

	// ! STEP 2 : Push everything into stack B except the LCS
	// ! STEP 3 : 
	// ! STEP 

	

	
}

// ! Calculer le cout total du premier element, et regarder a cout + 1 MAX au debut et a la fin