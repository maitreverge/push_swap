/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:15:53 by flverge           #+#    #+#             */
/*   Updated: 2024/01/24 18:28:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	a_is_sorted(t_node **a)
{
	t_node	*current;

	current = *a;
	if (!current->next)
		return (true);
	while (current->next)
	{
		if (current->nb > current->next->nb)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	a_contains_double(t_node **a)
{
	t_node	*current;
	t_node	*following_node;

	current = *a;
	while (current)
	{
		following_node = current->next;
		while (following_node)
		{
			if (current->nb == following_node->nb)
				return (true);
			following_node = following_node->next;
		}
		current = current->next;
	}
	return (false);
}

/**
 * @brief Make sure that every arg is a number
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit (1);
	while (i < ac)
	{
		if (ft_is_num(av[i]))
			return (1);
		i++;
	}
	return (0);
}
