/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:45:56 by flverge           #+#    #+#             */
/*   Updated: 2024/01/09 11:35:45 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*lstnew(int content)
{
	t_node	*new_element;

	new_element = (t_node *)malloc(sizeof(t_node));
	if (!new_element)
		return (NULL);
	new_element->nb = content;
	new_element->next = NULL;
	return (new_element);
}

void	lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	last = lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

t_node	*lstlast(t_node *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	free_stack(t_node *a)
{
	t_node	*current;
	t_node	*next;

	current = a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
