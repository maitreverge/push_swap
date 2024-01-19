/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:45:56 by flverge           #+#    #+#             */
/*   Updated: 2024/01/19 14:28:12 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	lstadd_back(t_node **lst, t_node *new)
{
	
}

t_node	*lstlast(t_node *lst)
{
	
}

void	free_stack(t_node *to_free)
{
	
}

