/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:45:56 by flverge           #+#    #+#             */
/*   Updated: 2024/01/19 14:58:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node *lst_last(t_node *lst)
{
	t_node *head;
	t_node *tail;

	// ! IF LIST == 1 NODE
	if (lst->next)
		return (lst);
	head = lst;
	tail = lst->next;
	while (tail->next != head)
		tail = tail->next;
	return (tail);
}

t_node	*lstnew(int number, int index)
{
	t_node *new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit;
	new_node->nb = number;
	new_node->master_index = index;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
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

void	lstadd_back(t_node **lst, t_node *new)
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
	int	i;

	if (!lst)
		return (0);
	if (lst->next == NULL)
		return (1);
	i = 1;

	
	return (i);	
}



void	free_stack(t_node *to_free)
{
	
}

