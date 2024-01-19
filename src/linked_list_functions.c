/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:45:56 by flverge           #+#    #+#             */
/*   Updated: 2024/01/19 17:57:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*lstlast(t_node *lst)
{
	t_node	*head;
	t_node	*tail;

	head = lst;
	if (!head)
		return (NULL);
	else if (head->next == NULL)
		return (head);
	tail = lst->next;
	while (tail->next != head)
		tail = tail->next;
	return (tail);
}

t_node	*lstnew(int number, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit ;
	new_node->nb = number;
	new_node->master_index = index;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	lstadd_back(t_node **lst, t_node *new)
{
	t_node	*head;
	t_node	*tail;

	head = *lst;
	tail = lstlast(*lst);
	if (!(*lst))
		return ;
	new->next = head;
	new->prev = tail;
	tail->next = new;
	head->prev = new;
}

void	lstadd_front(t_node **lst, t_node *new)
{
	if (!(*lst))
		return ;
	// ! EDGE CASE : if the list only got one node
	if ((*lst)->prev == NULL)
	{
		new->next = *lst;
		new->prev = *lst;
		(*lst)->next = new;
		(*lst)->prev = new;
		return ;
	}
	
}

int	lstsize(t_node *lst)
{
	t_node	*head;
	t_node	*tail;
	int		i;

	head = lst;
	if (!head)
		return (0);
	else if (head->next == NULL)
		return (1);
	i = 2;
	tail = lst->next;
	while (tail->next != head)
	{
		tail = tail->next;
		i++;
	}
	return (i);
}

void	free_stack(t_node *to_free)
{
	t_node	*current;
	t_node	*next;
	if (!to_free)
		return ;
	else if (!to_free->next)
	{
		free(to_free);
		return ;
	}
	current = to_free;
	current->prev->next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
