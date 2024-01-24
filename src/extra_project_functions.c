/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_project_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:15:06 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 16:15:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_simple(t_node *a, char *message)
{
	t_node	*head;

	head = a;
	printf("\033[32;1m%s\033[0m\n", message);
	if (!a)
		return ;
	do
	{
		printf("Node nb = %i\n", head->nb);
		head = head->next;
	} while (head);
}

void	print_full(t_node *a, char *message)
{
	t_node	*head;

	head = a;
	printf("\033[32;1m%s\033[0m\n", message);
	if (!a)
		return ;
	do
	{
		printf("Node adress = %p\n", head);
		printf("Node nb = %i\n", head->nb);
		printf("Node index = %zu\n", head->master_index);
		if (!head->prev)
			printf("\033[1;31mNode prev = %p\n\033[0m", head->prev); // red
		else
			printf("Node prev = %p\n", head->prev); // green
		if (!head->next)
			printf("\033[1;31mNode next = %p\n\n\033[0m", head->next);
		else
			printf("Node next = %p\n\n", head->next);
		head = head->next;
	} while (head);
}