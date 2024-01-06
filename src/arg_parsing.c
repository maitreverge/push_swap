/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:30:50 by flverge           #+#    #+#             */
/*   Updated: 2024/01/06 12:11:39 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

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

int	check_arg(int ac, char **av) // ! Making sure that every arg is a number
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_is_num(av[i]))
			return (1);
		i++;
	}
	return (0);
}
