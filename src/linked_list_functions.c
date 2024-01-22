/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:45:56 by flverge           #+#    #+#             */
/*   Updated: 2024/01/22 08:43:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*lstnew(int number, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nb = number;
	new_node->master_index = index;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_node	*lstlast(t_node *lst)
{
	t_node current;

	current = lst;
	if (!current)
		return (0);
	if (!current->next)	
		return (current);
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}


void	lstadd_back(t_node **lst, t_node *new)
{
	t_node *tail;

	tail = lstlast(*lst);
	tail->next = new;
	new->prev = tail;
}

void	lstadd_front(t_node **lst, t_node *new)
{

}

int	lstsize(t_node *lst)
{

}

void	free_stack(t_node *to_free)
{

}

void	free_node(t_node **to_free)
{

}
