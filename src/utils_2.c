/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:57:24 by flverge           #+#    #+#             */
/*   Updated: 2024/01/22 18:58:23 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
