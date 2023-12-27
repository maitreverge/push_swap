/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:30:50 by flverge           #+#    #+#             */
/*   Updated: 2023/12/27 18:41:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_double(t_node *a, int nb)
{
	
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
		if (check_double(*a, int(current_number)))
			exit(-1);
		
		
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
