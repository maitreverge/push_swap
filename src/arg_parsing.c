/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:30:50 by flverge           #+#    #+#             */
/*   Updated: 2023/12/28 14:26:09 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	

void	add_node(t_node **a, int current_number)
{
	t_node *node;

	if (!a)
		return NULL;	
	node = malloc(sizeof(t_node));
	if (!node)
		return NULL;
	// add adresses prev and next
	node->nb = current_number;
	node->next = NULL;
	if (*a == NULL) // FIRST NODE
	{
		a = node;
		node->prev = NULL;
	}
	else // NOT FIRST NODE
	{
				
	}
}

int	check_double(t_node *a, int nb)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->nb == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_stack(t_node **a, char **av)
{
	// While running accross the args, need to check_arg
	long current_number;

	while (*av)
	{
		current_number = ft_atol(*av);
		// ! INT MAX / INT MIN 
		if (current_number > INT_MAX || current_number < INT_MIN)
			exit(-1);
		// ! NUMBER REPETITION
		if (check_double(*a, (int)current_number))
			exit(-1);
		add_node(*a, (int)current_number);
		av++;
	}
}

int	check_arg(int ac, char **av) // ! Making sure that every arg is a number
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_is_num(av[i]))
			return 1;
		i++;
	}
	return (0);
}
