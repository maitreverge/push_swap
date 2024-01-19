/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:30:50 by flverge           #+#    #+#             */
/*   Updated: 2024/01/19 13:46:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

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
		return (i);
	while (i < ac)
	{
		if (ft_is_num(av[i]))
			return (1);
		i++;
	}
	return (0);
}
