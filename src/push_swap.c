/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2023/12/28 13:37:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	// t_node	*b;
	
	a = NULL;
	// b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0])) // if nothing promped, return
		return (-1);
	else if (ac >= 2)
	{
		if (check_arg(ac, av) == 1) // ! chekcs if it's only numbers
		{
			ft_printf("Error\n");
			return (-1);
		}
		if (ac == 2)
			av = ft_split(av[1], ' ');
	}
	init_stack(&a, av + 1);	
		
		
}
