/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:45:56 by flverge           #+#    #+#             */
/*   Updated: 2024/01/22 10:20:32 by flverge          ###   ########.fr       */
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
	t_node	*current;

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
	t_node	*tail;

	tail = lstlast(*lst);
	tail->next = new;
	new->prev = tail;
}

void	lstadd_front(t_node **lst, t_node *new)
{
	t_node	*head;

	head = *lst;
	head->prev = new;
	new->next = head;
	*lst = new;
}

int	lstsize(t_node *lst)
{
	t_node	*current;
	int		i;

	current = lst;
	if (!current)
		return (0);
	else if (!current->next)
		return (1);
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	free_stack(t_node *to_free)
{
	t_node	*current;

	current = to_free;
	if (!current)
		return ;
	else if (!current->next)
	{
		free(current);
		return ;
	}
	while (current)
	{
		if (!current->next)
		{
			free(current);
			return ;
		}
		current = current->next;
		free(current->prev);
	}
}

void	free_node(t_node **to_free)
{
	
}
